#include<stdio.h>
#include<Windows.h>
#define N 8
int main()
{
	int arr[N][N] = { 1 };
	int i = 0;
	for (i = 1; i <= N - 1; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}