#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXARGS 128

int parseline(char *buf, char *argv[]) {
  char *delim;
  int argc;
  int bg;
  buf[strlen(buf) - 1] = ' ';
  while (*buf && (*buf == ' '))
    buf++;

  argc = 0;
  while ((delim = strchr(buf, ' '))) {
    argv[argc++] = buf;
    *delim = '\0';
    buf = delim + 1;
    while (*buf && (*buf == ' '))
      buf++;
  }
  argv[argc] = NULL;
  if (argc == 0)
    return 1;

  if ((bg = (*argv[argc - 1] == '&')) != 0)
    argv[--argc] = NULL;
  return bg;
}

int builtin_command(char **argv) {
  if (!strcmp(argv[0], "quit"))
    exit(0);
  if (!strcmp(argv[0], "&"))
    return 1;
  return 0;
}

void eval(char *cmdline, char *arg[], char *envp[]) {
  int i = 0;
  while (arg[i])
    i++;
  char *argv[MAXARGS];
  char buf[MAXARGS];
  int bg;
  pid_t pid;

  strcpy(buf, cmdline);
  bg = parseline(buf, argv);
  if (argv[0] == NULL)
    return;
  if (!builtin_command(argv)) {
    if ((pid = fork()) == 0) {
      if (execve(argv[0], argv, envp) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(0);
      }

      if (!bg) {
        int status;
        if (waitpid(pid, &status, 0) < 0)
          fprintf(stdout, "%s: %s\n", "waitfg: waitpid error", strerror(1));
      } else {
        printf("%d %s", pid, cmdline);
      }
    }
  }
  return;
}

int main(int argc, char *argv[], char *envp[]) {
  char cmdline[MAXARGS];
  while (1) {
    printf("$ ");
    fgets(cmdline, MAXARGS, stdin);
    if (feof(stdin))
      exit(0);

    eval(cmdline, argv, envp);
  }
  return 0;
}
