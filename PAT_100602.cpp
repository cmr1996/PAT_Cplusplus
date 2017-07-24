#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	char str[100];
	int n;
	cin >> n;
	int j = -1, k = -1, l = -1;//j,k,l分别对应百、十、个位
	if (n<10)
	{
		l = n;
	}
	else if (n < 100)
	{
		l = n % 10;
		n = n / 10;
		k = n;
	}
	else
	{
		l = n % 10;
		n = n / 10;
		k = n % 10;
		n = n / 10;
		j = n;
	}
	char* temp = str;
	if (j>0)
	{
		for (int i = 0; i <j; i++)
		{
			*temp = 'B';
			temp++;
		}
	}
	if (k>0)
	{
		for (int i = 0; i < k; i++)
		{
			*temp = 'S';
			temp++;
		}
	}
	if (l>0)
	{
		for (int i = 0; i < l; i++)
		{
			*temp = i+1+'0';
			temp++;
		}
	}
	*temp = '\0';
	int i = 0;
	while (str[i]!='\0')
	{
		cout << str[i];
		i++;
	}
	return 0;
	}