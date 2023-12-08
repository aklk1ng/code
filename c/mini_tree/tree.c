#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define DEFAULT "\x1b[0m"
#define RED "\x1b[31;1m"
#define GREEN "\x1b[32;1m"
#define YELLOW "\x1b[33;1m"
#define BLUE "\x1b[34;1m"
#define CYAN "\x1b[36;1m"

#define MID "├── "
#define END "└── "

char *last_path = NULL;

void tree_print(const char *path, int level) {
  struct dirent **entries;
  int size = scandir(path, &entries, NULL, alphasort);
  for (int i = 0; i < size; i++) {
    struct dirent *dp = entries[i];
    if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
      continue;
    }
    if (level == 0 && i == size - 1) {
      last_path = (char *)malloc(sizeof(path) + sizeof(dp->d_name) + 2);
      sprintf(last_path, "%s/%s", path, dp->d_name);
    }
    char *prefix = "";
    if (i == size - 1) {
      prefix = END;
    } else {
      prefix = MID;
    }
    char *newpath = (char *)malloc(sizeof(path) + sizeof(dp->d_name) + 2);
    sprintf(newpath, "%s/%s", path, dp->d_name);
    for (int i = 0; i < level; i++) {
      printf("│   ");
    }
    printf("%s", prefix);

    // dir
    if ((dp->d_type == DT_DIR) && (access(newpath, R_OK) == 0)) {
      printf("%s%s%s\n", BLUE, dp->d_name, DEFAULT);
      tree_print(newpath, level + 1);
      free(newpath);
      continue;
    }

    // file
    struct stat buf;
    int r = lstat(newpath, &buf);
    if (S_ISLNK(buf.st_mode)) {
      printf("%s%s -> %s%s\n", CYAN, dp->d_name, realpath(newpath, NULL), DEFAULT);
      free(newpath);
      continue;
    }
    if (S_ISFIFO(buf.st_mode)) {
      printf("%s%s%s\n", YELLOW, dp->d_name, DEFAULT);
      free(newpath);
      continue;
    }
    if (access(newpath, X_OK) == 0) {
      printf("%s%s%s\n", GREEN, dp->d_name, DEFAULT);
      free(newpath);
      continue;
    }
    if (access(newpath, R_OK) == -1) {
      printf("%s%s%s\n", RED, dp->d_name, DEFAULT);
      free(newpath);
      continue;
    }
    if (S_ISREG(buf.st_mode)) {
      printf("%s\n", dp->d_name);
      free(newpath);
      continue;
    }
    free(newpath);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s [dir path]", argv[0]);
    return 1;
  }

  struct stat buf;
  int r = stat(argv[1], &buf);
  if (!S_ISDIR(buf.st_mode)) {
    fprintf(stderr, "Usage: %s [dir path]", argv[0]);
    return 1;
  }

  char *path = realpath(argv[1], NULL);
  printf("%s%s%s\n", CYAN, path, DEFAULT);
  tree_print(path, 0);
  printf("\n");
  free(path);

  return 0;
}
