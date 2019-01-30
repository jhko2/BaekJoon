/*#include<stdio.h>
#include<malloc.h>

void count_Sort(int *arr,int num,int max);
int maxarr(int *arr,int num);
int main()
{
	int n, i,max=0;
	int *arr;

	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	max = maxarr(arr, n); //입력받은 수 중 최대값 구하기
	count_Sort(arr,n,max);

	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}
int maxarr(int *arr,int num)
{
	int i,max = 0;
	for (i = 0; i < num; i++)
	{
		if (arr[i] >= max)
			max = arr[i];
	}
	return max;
}
void count_Sort(int *arr,int num, int max)
{
	int i, j;
	int *temparr;
	int t_point = 0;
	int *counting;//값 저장됨.

	temparr = (int *)malloc(sizeof(int)*num);
	counting = (int *)malloc(sizeof(int)*max-1);
	for (i = 0; i < max; i++)
		counting[i] = 0;
	for (i = 0; i < num; i++) //각 숫자가 몇번 나왔는지 계산
	{
		counting[arr[i]-1]++;
	}

	for (i = 0; i < max; i++) //counting 배열 0~max까지 확인하여 
	{							// 값 존재할경우 그 값만큼 배열에 넣는다.
		if (counting[i] != 0)
		{
			for (j = 0; j < counting[i]; j++)
			{
				temparr[t_point]=i+1;
				t_point++;
			}
		}
	}
	for (i = 0; i < num; i++)
		arr[i] = temparr[i];
}*/