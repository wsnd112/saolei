#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("****************  *********\n");
	printf("*******   1.play   *******\n");
	printf("*******   0.exit   ********\n");
	printf("***************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	displayboard(show, ROW, COL);
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	findmine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
