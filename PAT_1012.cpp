#include<stdio.h>

int main()
{
	int N;//��������
	scanf_s("%d", &N);
	//����
	int A1_sum = 0;//��A1��ż����
	int A2_sum = 0;//A2�ĺ�
	int A2_flag = 1;//A2�ı��λ
	int A2_cnt = 0;//A2����λ,����ͳ�Ʒ���A2Ҫ������Ƿ����
	int A3_cnt = 0;
	float A4_sum = 0;
	int A4_cnt = 0;
	int A5_max=0;//A5����������
	for (int j = 0; j < N; j++)
	{
		int n;
		scanf_s("%d", &n);
		int temp = n%5;
		switch (temp)
		{
		case 0:
			if (temp % 2 == 0)
			{
				A1_sum = A1_sum + temp;
			}
			break;
		case 1:
			if (A2_flag)
			{
				A2_sum = A2_sum + temp;
				A2_flag = -A2_flag;
			}
			else
			{
				A2_sum = A2_sum - temp;
				A2_flag = -A2_flag;
			}
			A2_cnt++;
			break;
		case 2:
			A3_cnt++;
			break;
		case 3:
			A4_sum = A4_sum + temp;
			A4_cnt++;
			break;
		case 4:
			if (temp>A5_max)
			{
				A5_max = temp;
			}
			break;
		}
	}

	if (A1_sum==0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ", A1_sum);
	}

	if (A2_cnt==0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ", A2_sum);
	}

	if (A3_cnt==0)
	{
		printf("N ");
	}
	else
	{
		printf("%d ", A3_cnt);
	}

	if (A4_sum==0)
	{
		printf("N ");
	}
	else
	{
		printf("%.1f ", A4_sum / A4_cnt);
	}
	
	if (A5_max==0)
	{
		printf("N");
	}
	else
	{
		printf("%d", A5_max);
	}
	return 0;
}