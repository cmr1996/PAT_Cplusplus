#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning(disable:4996);
using namespace std;

int main()
{
	int n;//�������ָ���
	cin >> n;
	vector<int> origin(n), target(n);//ԭ����,Ŀ������
	//���뺯��
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &origin[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &target[i]);
	}
	int flag = 0;//flag�Ǳ�־��,ȡ0��ʾ��������,ȡ1��ʾ�鲢����
	//��������������ǣ�ǰ��Ϊ����ģ�������ԭʼ����һ����
	//������ǲ����������ǹ鲢����
	int index = -1;
	for (int i = 1; i < n; i++)
	{
		if (target[i - 1] > target[i]) { 
			index = i; 
			break;
		}
	}
	for (int i = index; i < n; i++)
	{
		if (origin[i] != target[i]) {
			flag = 1;
			break;
		}
	}
	if (flag==0){
		sort(target.begin(), target.begin() + index + 1);
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < n-1; i++)
		{
			cout << target[i] << " ";
		}
		cout << target[n - 1];
	}
	else if (flag == 1)
	{
		int k = 1;
		bool isNotEqual = true;
		while (isNotEqual)
		{
			isNotEqual = false;
			if (origin != target){
				isNotEqual = true;
			}
			k *= 2;
			for (int i = 0; i < n/k; i++)
			{
				sort(origin.begin() + i*k, origin.begin() + (i + 1)*k);//��������Ȼ���ÿ������
			}
			sort(origin.begin() + (n / k) *k, origin.end());//��δ�����ʣ�ಿ������
		}
		cout << "Merge Sort" << endl;
		for (int i = 0; i < n-1; i++)
		{
			cout << origin[i] << " ";
		}
		cout << origin[n - 1];
	}

	return 0;
}