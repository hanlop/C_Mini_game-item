#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//扫雷控制台实现

//先实现出一个游戏菜单出来
void menu()
{
	printf("************************************\n");
	printf("*******   Mine Clearance     *******\n");
	printf("*******      1. paly         *******\n");
	printf("*******      0. exit         *******\n");
	printf("************************************\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		char mine1[ROWS][COLS];
		char mine2[ROWS][COLS];
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			system("cls");
			InitBoard(mine1,ROWS,COLS,'0');
			InitBoard(mine2, ROWS, COLS,'*');
			//PrintBoard(mine1, ROW, COL);
			//PrintBoard(mine2, ROW, COL);
			BuryMine(mine1, ROW, COL);
			/*PrintBoard(mine1, ROW, COL);*/
			RemoveMine(mine1,mine2, ROW, COL);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();

	return 0;
}