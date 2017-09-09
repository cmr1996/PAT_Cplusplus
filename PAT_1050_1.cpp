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
	
	sort(num, num + N, greater<int>()); //greater<int>对int整形进行降序排列

	for (int i = 0; i < N; i++)
	{
		cout << num[i] << ' ';
	}
	//
	cout << endl;
	int m = 0, n = 0, min = N;//行、列、最小值
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
	//动态分配二维数组
	int **screw = new int*[m + 1];//动态分配行
	for (int i = 0; i < m; i++)
	{
		screw[i] = new int[n + 1];//动态分配列
	}
	if (screw == NULL) { cout << "ERROR!" << endl; }//错误处理
	//memset(screw, 0, sizeof(screw));//初始化:向screw中填充零
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
		while (j + 1 < n && !screw[i][j + 1]) { screw[i][++j] = num[k++]; }//从左向右赋值，到右边界停止
		while (i + 1 < m && !screw[i + 1][j]) { screw[++i][j] = num[k++]; }//从上向下赋值，到下边界停止
		while (j - 1 >= 0 && !screw[i][j - 1]) { screw[i][--j] = num[k++]; }//从右向左赋值，到左边界停止
		while (i - 1 >= 0 && !screw[i - 1][j]) { screw[--i][j] = num[k++]; }//从下向上赋值，到上边界停止

	}//至于为什么要用++j，因为如果是j++，往下的时候，j需要减一，造成了后续的繁琐
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			if (j + 1 != n) { cout << screw[i][j] << ' '; }
			else { cout << screw[i][j] << endl; }
		}
	}

	return 0;
}