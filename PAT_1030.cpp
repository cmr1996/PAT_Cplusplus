#pragma warning(disable:4996);
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//tmp�Ǳ������е�����,max�Ǵ���������,max_index����������±�
int cnt_length(vector<int>& tmp, int max, int max_index, int cnt_p, int tmp_length)
{ //cnt_p�Ǵ���Ĳ���P,tmp_length��tmp�ĳ���,�����Ͽ��Լ�������ʱ��
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
	int N, P;//NΪ�����������ĸ���,PΪ�����Ĳ���
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

//���գ��޷�ͨ�����Ե��ĺͲ��Ե��壬�������ַ���