#pragma warning(disable:4996);
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//tmp是保存数列的向量,max是传入的最大数,max_index是最大数的下标
int cnt_length(vector<int>& tmp, int max, int max_index, int cnt_p, int tmp_length)
{ //cnt_p是传入的参数P,tmp_length是tmp的长度,理论上可以减少运行时间
	for (int i = 0; i < tmp_length; i++)
	{
		if (max<=tmp[i]*cnt_p)
		{
			return max_index - i + 1;
			break;
		}
	}
	return -1;
}

int main()
{
	int N, P;//N为输入正整数的个数,P为给定的参数
	scanf("%d%d", &N, &P);

	vector<int> num;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	
	sort(num.begin(), num.end());
	int max_len = -1;
	for (int i = N-1; i >=0 ; i--)
	{
		int len = cnt_length(num, num[i], i, P, N);
		if (len!=-1)
		{
			if (len > max_len)
			{
				max_len = len;
			}
		}
	}

	if (max_len==-1)
	{
		printf("0");
	}
	else
	{
		printf("%d", max_len);
	}
	return 0;
}

//最终，无法通过测试点四和测试点五，弃用这种方法