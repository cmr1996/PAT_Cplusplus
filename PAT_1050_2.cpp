#include<iostream>
#include<functional>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int num[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	sort(num, num + N, greater<int>()); //greater<int>��int���ν��н�������

	int m = 0, n = 0, min = N;//�С��С���Сֵ
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i*j == N&&i - j < min) {
				min = i - j;
				m = i;
				n = j;
			}
		}
	}

	//ֱ�ӷ����ά����
	int screw[m][n];
	memset(screw, 0, sizeof(screw));//��ʼ��:��screw�������

	int k = 0, i = 0, j = 0;
	//cout << num[0];
	screw[i][j] = num[k++];
	while (k<N)
	{
		while (j + 1 < n && !screw[i][j + 1]) { screw[i][++j] = num[k++]; }//�������Ҹ�ֵ�����ұ߽�ֹͣ
		while (i + 1 < m && !screw[i + 1][j]) { screw[++i][j] = num[k++]; }//�������¸�ֵ�����±߽�ֹͣ
		while (j - 1 >= 0 && !screw[i][j - 1]) { screw[i][--j] = num[k++]; }//��������ֵ������߽�ֹͣ
		while (i - 1 >= 0 && !screw[i - 1][j]) { screw[--i][j] = num[k++]; }//�������ϸ�ֵ�����ϱ߽�ֹͣ

	}//����ΪʲôҪ��++j����Ϊ�����j++�����µ�ʱ��j��Ҫ��һ������˺����ķ���
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			if (j + 1 != n) { printf("%d ", screw[i][j]); }
			else { printf("%d\n", screw[i][j]); }
		}
	}

	return 0;
}