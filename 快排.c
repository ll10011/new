int pation(int*array, int left, int right)//»®·Ö
{
	int begin = left;
	int end = right;
	int key = array[right - 1];
	while (begin<end)
	{
		while (begin<end&&array[begin] <= key)
			begin++;
		while (begin<end&&array[begin] >= key)
			end--;
		swap(&array[begin], &array[end]);
	}

	if (begin!=right-1)
		swap(&array[begin], &array[right-1]);
	return begin;
}


void QuickSort(int*array,int left,int right)//¿ìÅÅ
{
	if ((right - left) > 1)
	{
		int div = pation(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}