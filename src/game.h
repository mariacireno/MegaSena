#ifndef HEADER_GAME
#define HEADER_GAME

/* Maximum and minimum sizes definition */
#define MIN_SIZE 6
#define MAX_SIZE 15

/* Struct that represents a game */
typedef struct Game_t {
    int m;
    int* numbers;
} Game;

void quickSort (int* arr, int start, int end);
int isRepNumber (int* arr, int size, int value);

#endif
