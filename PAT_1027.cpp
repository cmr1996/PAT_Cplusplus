#pragma warning(disable:4996) 
#include<iostream>
#include<string>
#include<vector>
using namespace std;


//�㷨˼·���ڵȲ����еĺ͹�ʽ
//��2*i*i-1<N
//��num = i_max*2-1
//֮��ó�num*num�ľ���ͼ
int main()
{
	int N;
	char chr, space;
	scanf("%d%c%c", &N, &space, &chr);
	int max_index;//N�����ĵȲ������������������
	for (int i = 0; 2 * i*i - 1 <= N; i++)
	{
		if (2 * (i + 1)*(i + 1) - 1 > N)
			max_index = i;
	}

	int max_num = max_index * 2 - 1;
	if (N == 1)
	{
		printf("%c\n", chr);
		printf("%d", 0);
	}
	else
	{
		for (int i = 1; i <= max_num; i++)
		{
			for (int j = 1; j <= max_num; j++)
			{
				if ((j >= i&&j <= 2 * max_index- i) || (j >= 2*max_index-i && j <= i))
				{
					printf("%c", chr);
				}
				else if(j>=1&&j<=2*max_index-i)
				{
					printf(" ");
				}
				//��ӡ����
				if (j == max_num)
				{
					printf("\n");
				}
			}
		}
		printf("%d", N - 2 * max_index*max_index + 1);
	}	
	return 0;
}