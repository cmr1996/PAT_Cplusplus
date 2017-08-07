#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#pragma warning(disable:4996);
using namespace std;

int main()
{
	int n;//输入数字个数
	cin >> n;
	vector<int> origin(n), target(n);//原序列,目标序列
	//输入函数
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &origin[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &target[i]);
	}
	int flag = 0;//flag是标志物,取0表示插入排序,取1表示归并排序
	//插入排序的特征是，前面为有序的，后面与原始序列一样。
	//如果不是插入排序，则是归并排序
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
				sort(origin.begin() + i*k, origin.begin() + (i + 1)*k);//按大块分区然后对每块排序
			}
			sort(origin.begin() + (n / k) *k, origin.end());//对未排序的剩余部分排序
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