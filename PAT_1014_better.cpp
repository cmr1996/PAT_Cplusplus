#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int flag = 0;
	char day = NULL;
	char hour = NULL;
	for (int i = 0; i < s1.length(); i++)
	{
		if (i>=s2.length())
		{
			break;
		}
		if (s1[i]==s2[i]&&(s1[i]>='A'&&s1[i]<='G')&&flag==0)
		{
			day = s1[i];
			flag = 1;
			continue;
		}
		if (s1[i]==s2[i])
		{
			if ((s1[i]>='0'&&s1[i]<='9'||s1[i]>='A'&&s1[i]<='N')&&flag==1)
			{
				hour = s1[i];
				break;
			}
		}
	}
	//输出前两字符串运算结果
	string DAY[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int k = (day - 'A');
	cout << DAY[k] << " ";
	if (hour>='0'&&hour<='9')
	{
		cout << "0" << hour - '0' << ":";
	}
	else
	{
		cout << 10 + hour - 'A' << ":";
	}

	int cnt = 0;
	for (int j = 0; j < s3.length(); j++)
	{
		if (j>s4.length())
		{
			break;
		}
		if (s3[j]==s4[j])
		{
			if ((s3[j]>='A'&&s3[j]<='Z')||(s3[j]>='a'&&s3[j]<='z'))
			{
				cnt = j;
				break;
			}
		}
	}
	if (cnt<10)
	{
		cout << "0" << cnt;
	}
	else
	{
		cout << cnt;
	}
	return 0;
}