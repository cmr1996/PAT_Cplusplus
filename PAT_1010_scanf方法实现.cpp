#include<stdio.h>

int main()
{
	int xs, zs;//系数，指数
	int flag_first = 1;//首位标记
	while (scanf("%d%d",&xs,&zs)!=EOF)
	{
		if (flag_first) //flag_first为1是说明标记位在首位
		{
			if (zs!=0)
			{
				printf("%d %d", xs*zs, zs - 1);//首位打印"数字+空格+数字"
				flag_first = 0;
			}
		}
		else
		{
			if (zs!=0)
			{
				printf(" %d %d", xs*zs, zs - 1);
			}
		}
		if (flag_first)
		{
			printf("%d %d", 0, 0);
		}
	}
	return 0;
}