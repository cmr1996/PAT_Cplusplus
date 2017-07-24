#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int C1, C2;
	scanf("%d %d", &C1, &C2);
	int num = (C2 - C1)/100;
	int hour = num / 3600;
	int minute = (num - hour * 3600) / 60;
	int second = num - hour * 3600 - minute * 60;
	printf("%02d:%02d:%02d", hour, minute, second);
	return 0;
}