#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initboard(char board[ROWS][COLS], int rows, int cols, char x)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = x;
		}
	}

}

void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x,int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x - 1][y] + mine[x + 1][y] + mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] - 8 * '0';
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("���������꣺\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը����\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("����������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��Ӯ��\n");
	}
}