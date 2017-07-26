#pragma warning(disable:4996);
#include<iostream>
#include<stdio.h>
using namespace std;

int Is_Not_Same(char* k,char k2)//判断是否出现重复字符
{														//不重复返回1,重复返回0
	int cmp = 1;
	char* k1 = k;
	while (*k1!='\0')
	{
		if (*k1==k2)
		{
			cmp = 0;
			break;
		}
		else
		{
			cmp = 1;
		}
		k1++;
	}
	return cmp;
}

int main()
{
	char good_keyboard[81];
	char broken_keyboard[81];
	char broken_key[81];
	scanf("%s", good_keyboard);
	scanf("%s", broken_keyboard);
	char* k1 = good_keyboard;
	char* k2 = broken_keyboard;
	char* k3 = broken_key;

	*k3 = '\0';//终止符
	while (*k2!='\0')
	{
		while (*k1 != '\0')
		{
			if (*k1!=*k2)
			{
				if (Is_Not_Same(broken_key, toupper(*k1)))
				{
					*k3 = toupper(*k1);
					k3++;
					*k3 = '\0';
					k1++;
				}
				else
				{
					k1++;
				}
			}
			else
			{
				k2++;
				k1++;
			}
		}
	}

	while (*k1!='\0')
	{
		if (Is_Not_Same(broken_key, toupper(*k1)))
		{
			*k3 = toupper(*k1);
			k3++;
			*k3 = '\0';
			k1++;
		}
		else
		{
			k1++;
		}
	}

	printf("%s", broken_key);
	return 0;
}