#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char fill)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = fill;
		}
	}
}

void PrintBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//1代表有雷 0代表无雷
void BuryMine(char arr[ROWS][COLS], int row, int col)
{
	int count = COUNT;

	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		arr[x][y] = '1';
		count--;
	}
}

int StatiMine(char arr[ROWS][COLS], int x, int y)
{
	return arr[x - 1][y - 1] - '0' +
		arr[x - 1][y] - '0' +
		arr[x - 1][y + 1] - '0' +
		arr[x][y - 1] - '0' +
		arr[x][y] - '0' +
		arr[x][y + 1] - '0' +
		arr[x + 1][y - 1] - '0' +
		arr[x + 1][y] - '0' +
		arr[x + 1][y + 1] - '0';
}
void RemoveMine(char arr1[ROWS][COLS], char arr2[ROWS][COLS], int row, int col)
{
	PrintBoard(arr2, row, col);
	int x = 0;
	int y = 0;
	int count = ROW * COL;
	while (count>COUNT)
	{
		printf("请输入你要排雷的坐标:");
		scanf("%d %d", &x, &y);
		if (x <= 0 || x>ROW || y <= 0 || y>COL)
		{
			printf("输入的坐标有误，请重新输入\n");
		}
		else if (arr1[x][y] == '1')
		{
			printf("你踩到雷了，游戏结束\n");
			PrintBoard(arr1, row, col);
			break;
		}
		else
		{
			int num = StatiMine(arr1, x, y);
			arr2[x][y] = num + '0';
			system("cls");
			PrintBoard(arr2, row, col);
			count--;
		}
	}

	if (count == COUNT)
	{
		printf("恭喜你排雷成功\n");
	}
}