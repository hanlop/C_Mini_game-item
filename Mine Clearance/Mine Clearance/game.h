#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 10 //À×µÄ¸öÊý

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char fill);
void PrintBoard(char arr[ROWS][COLS], int row, int col);
void BuryMine(char arr[ROWS][COLS], int row, int col);
void RemoveMine(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int row, int col);