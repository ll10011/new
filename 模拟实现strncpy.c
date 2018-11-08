#include<stdio.h>
#include<Windows.h>
#include<assert.h>
char *MyStrncpy(char*str1, const char*str2, int n)
{
	char*tmp = str1;
	assert(str1);
	assert(str2);
	while (n--)
	{
		*str1 ==*str2;
		*str1++;
		*str2++;
	}
	return tmp;
}
int main()
{
	char str1[20] = { 1 };
	char str2 = "abcde";
	printf("%s\n", MyStrncpy(str1, str2, 3));
	system("pause");
	return 0;
}