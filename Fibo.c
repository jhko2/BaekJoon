#include<stdio.h>
#include<malloc.h>

unsigned long long Arr[2][2] = { { 1,1 },{ 1,0 } }; //기본행렬

unsigned long long MulMat(unsigned long long n)//Matrix a / 회수 n
{
	unsigned long long i;
	unsigned long long T_Arr[2][2] = { { 1,1 },{ 1,0 } };
	unsigned long long R_Arr[2][2] = { { 1,1 },{ 1,0 } };
	if ((n == 1) || (n == 2))
		return 1;
	else if (n == 0)
		return 0;
	else
	{
		if (n % 2 == 0) //짝수
		{
			T_Arr[0][0] = MulMat(n / 2); //분할
			T_Arr[0][1] = MulMat(n / 2 - 1);
			T_Arr[1][0] = MulMat(n / 2 - 1);
			T_Arr[1][1] = MulMat(n / 2 - 2);

			R_Arr[0][0] = (T_Arr[0][0] * T_Arr[0][0]) + (T_Arr[1][0] * T_Arr[0][1]); //정복
			R_Arr[0][1] = T_Arr[0][0] * T_Arr[0][1] + T_Arr[0][1] * T_Arr[1][1];
			R_Arr[1][0] = R_Arr[0][1];
			R_Arr[1][1] = T_Arr[1][0] * T_Arr[0][1] + T_Arr[1][1] * T_Arr[1][1];
		}
		else //홀수
		{
			if (n == 3)
				return 2;
			else
			{
				T_Arr[0][0] = MulMat(n / 2); //분할
				T_Arr[0][1] = MulMat(n / 2 - 1);
				T_Arr[1][0] = MulMat(n / 2 - 1);
				T_Arr[1][1] = MulMat(n / 2 - 2);

				R_Arr[0][0] = (T_Arr[0][0] * T_Arr[0][0]) + (T_Arr[1][0] * T_Arr[0][1]); //정복
				R_Arr[0][1] = T_Arr[0][0] * T_Arr[0][1] + T_Arr[0][1] * T_Arr[1][1];
				R_Arr[1][0] = R_Arr[0][1];
				R_Arr[1][1] = T_Arr[1][0] * T_Arr[0][1] + T_Arr[1][1] * T_Arr[1][1];

				R_Arr[0][0] = (R_Arr[0][0] * Arr[1][0]) + (R_Arr[1][0] * Arr[0][1]); //정복--> 홀수는 뒤에 Arr을 한번 더 곱해준다
				R_Arr[0][1] = R_Arr[0][0] * Arr[0][1] + R_Arr[0][1] * Arr[1][1];
				R_Arr[1][0] = R_Arr[0][1];
				R_Arr[1][1] = R_Arr[1][0] * Arr[0][1] + R_Arr[1][1] * Arr[1][1];
			}
		}
		return R_Arr[0][0];
	}
}
int main()
{
	unsigned long long n;
	unsigned long long temp;
	int p = 1500000; //주기 150만 --> 10^n일 경우 주기는 15*10^n-1 (n>2)일경우

	scanf("%lld", &n);

	n = n%p;
	if (n == 0) //temp가0일경우 계산이 안되므로 150만으로맞춰준다.
		n = p;

	temp = MulMat(n);

	printf("%lld", temp);

	return 0;
}
