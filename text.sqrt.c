#include <stdio.h>
#include <string.h>
#include <Windows.h>
//int int_cmp(const void*n1, const void*n2)
//{
//	return *(int*)n1 - *(int*)n2;
//}
//
//int float_cmp(const void*n1, const void*n2)
//{
//	float ret = *(float*)n1 - *(float*)n2;
//	if (ret == 0)
//		return 0;
//	else if (ret < 0)
//		return -1;
//	else
//		return 1;
//}

int str_cmp(const void*n1, const void*n2)
{
	return strcmp(*(char**)n1, *(char**)n2);
}

int main()
{
	/*int arr1[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arr2[] = { 0.5, 1.5, 5.5, 3.5, 2.5 };*/
	char*arr3[] = { "aaaa", "cccc", "bbbb" };
	//int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	//int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int sz3 = sizeof(arr3) / sizeof(arr3[0]);
	//qsort(arr1, sz1, sizeof(int), int_cmp);
	//qsort(arr2, sz2, sizeof(int), float_cmp);
	qsort(arr3, sz3, sizeof(int), str_cmp);
	/*for (int i = 0; i < sz1; i++)
	{
	printf("%d", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i < sz1; i++)
	{
	printf("%f", arr2[i]);
	}
	printf("\n");*/
	for (int i = 0; i < sz3; i++)
	{
		printf("%s", arr3[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}