#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

//���ֵ��Ϊ���������������ԭ��������ǰ��ǰi���������ֵ����

int main()
{
	int N;
	int num[100001];
	int tmp[100001];
	int ans[100001];
	ans[0] = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		tmp[i] = num[i];
	}
	sort(tmp, tmp + N);//��С��������
	int max = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (num[i] > max) { max = num[i]; }
		if (num[i] == tmp[i] && num[i] == max) { ans[cnt++] = num[i]; }
	}

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (i == 0) { cout << ans[i]; }
		else { cout << ' ' << ans[i]; }
	}
	cout << endl;//ע���ʽ����
	return 0;
}