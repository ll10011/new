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
	printf("***********   ɨ  ��  ***********\n");
	printf("*****       1.��ʼ��Ϸ      *****\n");
	printf("*****       2.�˳���Ϸ      *****\n");
	printf("*********************************\n");
}

void ShowMine(char show[ROW][COL], int row, int col)//��ӡ����
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
void SetMine(char arr[ROW][COL], int row, int col)//����
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

int GetMine(char arr[ROW][COL], int x, int y)//�ܱ�����
{
	return arr[x - 1][y - 1] + arr[x - 1][y] + arr[x - 1][y + 1] + \
		arr[x][y - 1] + arr[x][y + 1] + \
		arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1] - 8 * '0';

}

void OpenMine(char arr[ROW][COL], char show[ROW][COL], int row, int col, int x, int y)//չ��������
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

void MoveMine(char arr[ROW][COL], char show[ROW][COL], int row, int col)//ȷ����һ�β��ᱻը��
{
	int x = 0;
	int y = 0;
	int c = 0;
	int ret = 1;
	printf("���������꣺��");
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

int IsWin(char show[ROW][COL], int row, int col)//�ж���Ӯ
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

void FindMine(char arr[ROW][COL], char show[ROW][COL], int row, int col)//����
{
	int x = 0;
	int y = 0;
	int c = 0;
	while (1)
	{
		printf("���������꣺��");
		scanf("%d %d", &x, &y);
		if (IsWin(show, row, col) == COUNT)
		{
			printf("��ϲ�㣬���׳ɹ�\n");
			ShowMine(arr, ROW, COL);
		}
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= COL - 2)
		{
			if (arr[x][y] == '1')//�ж��Ƿ�Ϊ��
			{
				printf("���ź����㱻ը����\n");
				ShowMine(arr, row, col);
				break;
			}
			else //��������ף���ȡ��Χ�׵ĸ�����չ��
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
			printf("����������������\n");
			break;
		}

		}
	}

	void game()
	{

		char arr[ROW][COL] = { 0 };
		char show[ROW][COL] = { 0 };
		memset(arr, '0', sizeof(arr));
		memset(show, '*', sizeof(show));//��ʼ��
		ShowMine(arr, ROW, COL);
		SetMine(arr, ROW, COL);//����
		ShowMine(show, ROW, COL);
		MoveMine(arr, show, ROW,COL);//��һ�β���ը
		FindMine(arr, show, ROW, COL);//����
	}

	int main()
	{
		srand((unsigned int)time(NULL));
		int input = 0;
		do
		{
			menu();
			printf("���������꣺��");
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
				printf("�������\n");
				break;
			}
		} while (input);
		system("pause");
		return 0;
	}






























