#ifndef _GAME_H_
#define _GAME_H_

#define ROW 11
#define COL 11
#define COUNT 5


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int GetRandIndex(int start, int end);
void ShowMine(char arr[ROW][COL], int row, int col);
void FindMine(char Mine[ROW][COL], char show[ROW][COL], int row, int col);
int IsWin(char show[ROW][COL], int row, int col);
int GetMine(char Mine[ROW][COL], int x, int y);
void MoveMine(char arr[ROW][COL], char show[ROW][COL], int row, int col);
void OpenMine(char arr[ROW][COL], char show[ROW][COL], int row, int col, int x, int y);
int IsWin(char show[ROW][COL], int row, int col);
void menu();


#pragma warning(disable:4996)

#endif




void menu()
{
	printf("*********************************\n");
	printf("***********   扫  雷  ***********\n");
	printf("*****       1.开始游戏      *****\n");
	printf("*****       2.退出游戏      *****\n");
	printf("*********************************\n");
}

void ShowMine(char show[ROW][COL], int row, int col)//打印雷盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col - 2; i++)
	{
		printf("%2d", i);
	}
	printf("\n");
	for (i = 1; i <= row - 2; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col - 2; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}

}

static int GetRandIndex(int start, int end)
{
	return rand() % (end - start + 1) + start;
}
void SetMine(char arr[ROW][COL], int row, int col)//埋雷
{
	int x = 0;
	int y = 0;
	int k = COUNT;
	while (k)
	{
		int x = GetRandIndex(1, row - 2);
		int y = GetRandIndex(1, col - 2);
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			k--;
		}
	}
}

int GetMine(char arr[ROW][COL], int x, int y)//周边雷数
{
	return arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1] + \
		arr[x][y - 1] + arr[x][y + 1] + \
		arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1] - 8 * '0';

}

void OpenMine(char arr[ROW][COL], char show[ROW][COL], int row, int col, int x, int y)//展开非雷区
{
	int c = 0;
	c = GetMine(arr, x, y);
	if (c == 0)
	{
		show[x][y] = ' ';
		if (x - 1>0 && y>0 && show[x - 1][y] == '*')
			OpenMine(arr, show, row, col, x - 1, y);

		if (x - 1>0 && y + 1 <= col && show[x - 1][y + 1] == '*')
			OpenMine(arr, show, row, col, x - 1, y + 1);

		if (x>0 && y + 1 <= col && show[x][y + 1] == '*')
			OpenMine(arr, show, row, col, x, y + 1);

		if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == '*')
			OpenMine(arr, show, row, col, x + 1, y + 1);

		if (x + 1 <= row && y>0 && show[x + 1][y] == '*')
			OpenMine(arr, show, row, col, x + 1, y);

		if (x + 1 <= row && y - 1>0 && show[x + 1][y - 1] == '*')
			OpenMine(arr, show, row, col, x + 1, y - 1);

		if (x>0 && y - 1>0 && show[x][y - 1] == '*')
			OpenMine(arr, show, row, col, x, y - 1);

		if (x - 1>0 && y - 1>0 && show[x - 1][y - 1] == '*')
			OpenMine(arr, show, row, col, x - 1, y - 1);
	}
	else
	{
		show[x][y] = GetMine(arr, x, y) + '0';
	}
}

void MoveMine(char arr[ROW][COL], char show[ROW][COL], int row, int col)//确保第一次不会被炸死
{
	int x = 0;
	int y = 0;
	int c = 0;
	int ret = 1;
	printf("请输入坐标：》");
	scanf("%d %d", &x, &y);
	if (arr[x][y] == '1')
	{
		arr[x][y] = '0';
		c = GetMine(arr, x, y);
		show[x][y] = c + '0';
		while (ret)
		{
			int x = GetRandIndex(1, row - 2);
			int y = GetRandIndex(1, col - 2);
			if (arr[x][y] == '0')
			{
				arr[x][y] = '1';
				ret--;
			}
		}
	}
	OpenMine(arr, show, row, col, x, y);
	ShowMine(show, row, col);
}

int IsWin(char show[ROW][COL], int row, int col)//判断输赢
{
	int i = 0;
	int j = 0;
	int c = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				c++;
			}
		}
	}
	return c;
}

void FindMine(char arr[ROW][COL], char show[ROW][COL], int row, int col)//排雷
{
	int x = 0;
	int y = 0;
	int c = 0;
	while (1)
	{
		printf("请输入坐标：》");
		scanf("%d %d", &x, &y);
		if (IsWin(show, row, col) == COUNT)
		{
			printf("恭喜你，排雷成功\n");
			ShowMine(arr, ROW, COL);
		}
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= COL - 2)
		{
			if (arr[x][y] == '1')//判断是否为雷
			{
				printf("很遗憾，你被炸死了\n");
				ShowMine(arr, row, col);
				break;
			}
			else //如果不是雷，获取周围雷的个数并展开
			{
				int c = GetMine(arr, x, y);
				show[x][y] = c + '0';
				OpenMine(arr, show, row, col, x, y);
				ShowMine(show, row, col);
				if (IsWin(show, row, col) == COUNT)
				{
					break;
				}

			}
		}
		else
		{
			printf("输入错误，请从新输入\n");
			break;
		}

		}
	}

	void game()
	{

		char arr[ROW][COL] = { 0 };
		char show[ROW][COL] = { 0 };
		memset(arr, '0', sizeof(arr));
		memset(show, '*', sizeof(show));//初始化
		ShowMine(arr, ROW, COL);
		SetMine(arr, ROW, COL);//布雷
		ShowMine(show, ROW, COL);
		MoveMine(arr, show, ROW,COL);//第一次不会炸
		FindMine(arr, show, ROW, COL);//排雷
	}

	int main()
	{
		srand((unsigned int)time(NULL));
		int input = 0;
		do
		{
			menu();
			printf("请输入坐标：》");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("输入错误\n");
				break;
			}
		} while (input);
		system("pause");
		return 0;
	}






























