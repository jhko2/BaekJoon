#include<stdio.h>

int lcm(int x, int y);

int main()
{
	int num;
	int x, y; //ī�״޷� ��
	int i, j;
	int m, n; //�Է¹޴� ��
	int lc;
	int count = 1;
	scanf("%d", &num); //ȸ��

	for (i = 0; i < num; i++)
	{
		scanf("%d %d %d %d", &x, &y, &m, &n);//1~40000
		if (!((x >= 1) && (y >= 1) && (x <= 40000) && (y <= 40000) && (m >= 1) && (m <= x) && (n <= y) && (n >= 1)))
			continue;
		lc = lcm(x, y);

		j = m; //��ȭ�Ͽ� ���������� ���� �´��� ã�� �� ��
		count = m; //������� ã������ �� �˻�

		while (1)
		{
			if (j > n)
			{
				if (j%y == 0)
					j = y;
				else
					j = j%y; //j�� y���� ũ�ٸ� �������� �����ش�.
			}
			if (j == n) // j�� N�̶� ���ٸ� ���
			{
				printf("%d\n", count);
				break;
			}
			else if (count >= lc) //�ּҰ�������� Ŀ����
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
int lcm(int x, int y) //�ּҰ���� ���ϱ�
{
	int temx, temy;
	temx = x;
	temy = y;
	while (y != 0) //�ּҰ���� ���ϱ�
	{
		int tem;
		tem= x%y;
		x = y;
		y = tem;
	} //x�� �ִ����� �����

	return temx*temy / x;
}