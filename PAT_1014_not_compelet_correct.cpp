#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string DATE(char temp)
{
	switch (temp)
	{
	case 'A':
		return "MON";
	case 'B':
		return "TUE";
	case 'C':
		return "WED";
	case 'D':
		return "THU";
	case 'E':
		return "FRI";
	case 'F':
		return "SAT";
	case 'G':
		return "SUN";
	}
}

string HOUR(char temp)
{
	if (temp >= '0'&&temp <= '9')
	{
		int k = temp - '0';
		string ans = "0"+to_string(k);
		return ans;
	}
	else
	{
		int k = (temp - 'A') + 10;
		string ans = to_string(k);
		return ans;
	}
}


int main()
{
	char str1[61], str2[61], str3[61], str4[61];
	cin.getline(str1, 61);
	cin.getline(str2, 61);
	cin.getline(str3, 61);
	cin.getline(str4, 61);
	//处理前两串字符串
	char temp1, temp2;
	temp1 = NULL;
	temp2 = NULL;
	for (int i = 0; i < 60; i++)
	{
		if (str1[i]=='\0'||str2[i]=='\0')
		{
			break;
		}
		else
		{
			if (str1[i] == str2[i])
			{
				if (temp1 != NULL)
				{
					temp1 = str1[i];
				}
				else
				{
					temp2 = str1[i];
				}
			}
		}
	}
		//处理前两串的输出结果
	string ans1;
	ans1 = DATE(temp1);
	string ans2;
	ans2 = HOUR(temp2);

	//处理后两串字符串
	int minute = 0;//分钟位
	for (int j = 0; j < 60; j++)
	{
		if (str3[j]=='\0'||str4[j]=='\0')
		{
			break;
		}
		else
		{
			if (str3[j]==str4[j])
			{
				minute = j;
				break;
			}
		}
	}
	string ans3;
	if (minute<10)
	{
		ans3 = " " + to_string(minute);
	}
	else
	{
		ans3 = to_string(minute);
	}

	string ans;
	ans = ans1 + " " + ans2 + ":" + ans3;
	cout << ans;
	return 0;
}