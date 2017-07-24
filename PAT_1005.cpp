#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include <functional>  
using namespace std;

//�������л�ȡ�����ǵ���
void get_overlap_number(set<int>& st, int n) //stΪ���汻����ֵ�ļ��ϣ���λ�ؼ���
{
	while (n != 1)
	{
		n = (n % 2) ? ((3 * n + 1) / 2) : (n / 2);
		st.insert(n);
	}
}

int main()
{
	set<int> st;//���汻�������ļ���
	set<int> key;//����ؼ����ļ���
	int total;//�������������
	cin >> total;
	vector<int> input_num;//�������������
	for (int i = 0; i<total; i++)
	{
		int num;
		cin >> num;
		input_num.push_back(num);
		get_overlap_number(st, num);
	}

	vector<int> answer;
	for (int i = 0; i < input_num.size(); i++)
	{
		if (st.find(input_num[i])==st.end())
		{
			answer.push_back(input_num[i]);
		}
	}
	sort(answer.begin(), answer.end(), greater<int>());
	for (int i = 0; i < answer.size(); i++)
	{
		if (i!=answer.size()-1)
		{
			cout << answer[i] << ' ';
		}
		else
		{
			cout << answer[i];
		}
	}
	return 0;
}