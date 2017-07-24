#include<iostream>
using namespace std;

int main() 
{
	int FIRST_cnt[3] = { 0 };//FIRST对应甲,0、1、2分别对应胜、平、负
	int FIRST_BCJ_cnt[3] = { 0 };//FIRST对应甲,0、1、2分别对应布、锤子、剪刀
	int SECOND_cnt[3] = { 0 };//FIRST对应乙,0、1、2分别对应胜、平、负
	int SECOND_BCJ_cnt[3] = { 0 };//FIRST对应乙,0、1、2分别对应布、锤子、剪刀
	int N;//总数
	cin >> N;

	char first, second;
	for (int i = 0; i < N; i++)
	{
		cin >> first >> second;
		if ((first == 'C'&&second == 'C') || (first == 'J'&&second=='J')||(first=='B'&&second=='B'))
		{
			FIRST_cnt[1]++;
			SECOND_cnt[1]++;
		}
		else if ((first == 'C'&&second=='J')||(first=='J'&&second=='B')||(first=='B'&&second=='C'))
		{
			FIRST_cnt[0]++;
			SECOND_cnt[2]++;
			if (first=='C')
			{
				FIRST_BCJ_cnt[1]++;
			}
			else if (first=='J')
			{
				FIRST_BCJ_cnt[2]++;
			}
			else
			{
				FIRST_BCJ_cnt[0]++;
			}
		}
		else
		{
			FIRST_cnt[2]++;
			SECOND_cnt[0]++;
			if (second == 'C')
			{
				SECOND_BCJ_cnt[1]++;
			}
			else if (second == 'J')
			{
				SECOND_BCJ_cnt[2]++;
			}
			else
			{
				SECOND_BCJ_cnt[0]++;
			}
		}
	}

	int first_maxIndex = 0;
	for (int i = 0; i < 3; i++)
	{
		if (FIRST_BCJ_cnt[first_maxIndex] < FIRST_BCJ_cnt[i])
		{
			first_maxIndex = i;
		}
	}

	int second_maxIndex = 0;
	for (int i = 0; i < 3; i++)
	{
		if (SECOND_BCJ_cnt[second_maxIndex] < SECOND_BCJ_cnt[i])
		{
			second_maxIndex = i;
		}
	}
	cout << FIRST_cnt[0] << " " << FIRST_cnt[1] << " " << FIRST_cnt[2] << endl;
	cout << SECOND_cnt[0] << " " << SECOND_cnt[1] << " " << SECOND_cnt[2] << endl;
	if (first_maxIndex==0)
	{
		cout << "B ";
	}
	else if (first_maxIndex==1)
	{
		cout << "C ";
	}
	else
	{
		cout << "J ";
	}

	if (second_maxIndex == 0)
	{
		cout << "B ";
	}
	else if (second_maxIndex == 1)
	{
		cout << "C ";
	}
	else
	{
		cout << "J ";
	}
	return 0;
}