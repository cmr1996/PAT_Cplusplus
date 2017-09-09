#include<iostream>
#include<functional>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *num = new int[N];
	for (int i=0; i < N; i++)
	{
		cin >> num[i];
	}
	
	sort(num, num + N, greater<int>()); //greater<int>��int���ν��н�������

	for (int i = 0; i < N; i++)
	{
		cout << num[i] << ' ';
	}
	//
	cout << endl;
	int m = 0, n = 0, min = N;//�С��С���Сֵ
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <=i ; j++)
		{
			if (i*j == N&&i - j < min) {
				min = i - j;
				m = i;
				n = j;
			}
		}
	}
	//cout << m << n;
	//��̬�����ά����
	int **screw = new int*[m + 1];//��̬������
	for (int i = 0; i < m; i++)
	{
		screw[i] = new int[n + 1];//��̬������
	}
	if (screw == NULL) { cout << "ERROR!" << endl; }//������
	//memset(screw, 0, sizeof(screw));//��ʼ��:��screw�������
	else {
		for (int i = 0; i < m; i++)	
		{
			for (int j = 0; j < n; j++) {
				screw[i][j] = 0;
			}
		}
	}

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
			if (j + 1 != n) { cout << screw[i][j] << ' '; }
			else { cout << screw[i][j] << endl; }
		}
	}

	return 0;
}