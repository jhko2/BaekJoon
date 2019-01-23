#include<stdio.h>

int lcm(int x, int y);

int main()
{
	int num;
	int x, y; //카잉달력 수
	int i, j;
	int m, n; //입력받는 수
	int lc;
	int count = 1;
	scanf("%d", &num); //회수

	for (i = 0; i < num; i++)
	{
		scanf("%d %d %d %d", &x, &y, &m, &n);//1~40000
		if (!((x >= 1) && (y >= 1) && (x <= 40000) && (y <= 40000) && (m >= 1) && (m <= x) && (n <= y) && (n >= 1)))
			continue;
		lc = lcm(x, y);

		j = m; //변화하여 지속적으로 값이 맞는지 찾게 될 수
		count = m; //몇번만에 찾아지는 지 검색

		while (1)
		{
			if (j > n)
			{
				if (j%y == 0)
					j = y;
				else
					j = j%y; //j가 y보다 크다면 나머지로 맞춰준다.
			}
			if (j == n) // j가 N이랑 같다면 출력
			{
				printf("%d\n", count);
				break;
			}
			else if (count >= lc) //최소공배수보다 커지면
			{
				printf("-1\n");
				break;
			}
			else
			{
				count = count + x;
				j = j + x;
			}
		}
	}
}
int lcm(int x, int y) //최소공배수 구하기
{
	int temx, temy;
	temx = x;
	temy = y;
	while (y != 0) //최소공배수 구하기
	{
		int tem;
		tem= x%y;
		x = y;
		y = tem;
	} //x에 최대공약수 저장됨

	return temx*temy / x;
}