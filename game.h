#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 9
#define COL 9
#define EASY_COUNT 10
#define ROWS ROW+2
#define COLS COL+2
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void initboard(char board[ROWS][COLS], int rows, int cols, char x);
void displayboard(char board[ROWS][COLS], int row, int col);
void setmine(char arr[ROW][COL],int row, int col);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
