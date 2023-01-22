#include <asm-generic/ioctls.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

const char CHARS[] = "!@#$%^&*()[]{};<>=-+BOXHACK";

struct blue_pill {
    char *rsi;
    float speed;
    int lifespan;
    float cycle;
};

void handle_signal(int sig) {
    printf("\e[?25h");
    exit(0);
}


int main (int argc, char *argv[])
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    const int COLS = w.ws_col;
    const int ROWS = w.ws_row;
    time_t t;
    struct blue_pill matrix[COLS];
    signal(SIGINT, handle_signal);
    srand((unsigned)time(&t));
    for (int c = 0; c < COLS; c++) {
        matrix[c].rsi = malloc(sizeof(char) * ROWS);
        matrix[c].speed = (((float)rand() / (float)RAND_MAX) + 0.1) / 2;
        matrix[c].cycle = rand() % ROWS;
        matrix[c].lifespan = (rand() % (ROWS / 2 + (ROWS / 4))) - (ROWS / 4);

        for (int r = 0; r < ROWS; r++) {
            matrix[c].rsi[r] = CHARS[rand() % (sizeof(CHARS) - 1)];
        }
    }
    printf("\e[?251");
    printf("\n1b2j");

    for(;;) {
        printf("\x1b[H");
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (r - 3 > matrix[c].cycle - matrix[c].lifespan && r < matrix[c].cycle - 2) {
                    // GREEN
                    printf("\e[38;2;10;220;10m");
                    printf("%c", matrix[c].rsi[r]);
                } else if (r - 1 > matrix[c].cycle - matrix[c].lifespan && r < matrix[c].cycle - 2) {
                    // DK GREEN 1
                    printf("\e[38;2;10;150;10m");
                    printf("%c", matrix[c].rsi[r]);
                } else if (r > matrix[c].cycle - matrix[c].lifespan && r < matrix[c].cycle - 2) {
                    // DK GREEN 2
                    printf("\e[38;2;10;90;10m");
                    printf("%c", matrix[c].rsi[r]);
                } else if (r + 1 < matrix[c].cycle && r + 2 > matrix[c].cycle) {
                    //LT GREEN 
                    printf("\e[38;2;170;255;170m");
                    printf("%c", matrix[c].rsi[r]);
                } else if (r < matrix[c].cycle && r + 1 > matrix[c].cycle) {
                    // WHITE
                    printf("\e[38;2;255;255;255m");
                    printf("%c", matrix[c].rsi[r]);
                } else {
                    printf(" ");
                }
            }

            if (r < ROWS - 1) {
                printf("\n");
            }
        }
        // cycle
        for (int c = 0; c < COLS; c++) {
            // MUTATIONS
            for (int r = 0; r < ROWS; r++) {
                if (rand() % 100 > 95) {
                    matrix[c].rsi[r] = CHARS[rand() % sizeof(CHARS) - 1];
                }
            }
            matrix[c].cycle += matrix[c].speed;
            if (matrix[c].cycle > ROWS + matrix[c].lifespan) {
                matrix[c].rsi = malloc(sizeof(char) * ROWS);
                matrix[c].speed =((float)rand() / (float)RAND_MAX + 0.1) / 2;
                matrix[c].cycle = 0;
                matrix[c].lifespan = (rand() % ROWS + (ROWS / 2)) - (ROWS / 2);

                for (int r = 0; r < ROWS; r++) {
                    matrix[c].rsi[r] = CHARS[rand() % (sizeof(CHARS) - 1)];
                }
            }
        }
        usleep(16000);
    }
    return 0;
}
