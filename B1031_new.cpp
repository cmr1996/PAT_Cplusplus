#pragma warning (disable:4996)
#include<cstdio>
#include<cstring>
//权值
int w[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//校验码
char z_m[11] = { '1','0','X','9','8','7','6','5','4','3','2' };

int main()
{
	int n;
	int sum = 0;//正确计数
	bool flag = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char tmp[18];
		int last = 0;
		scanf("%s", tmp);
		int j = 0;
		for (; j < 17; j++)
		{   //出现不合法数字就结束整个循环
			if (tmp[j]<'0' || tmp[j]>'9') { break; }//break结束整个循环体
			last += (tmp[j] - '0')*w[j];
		}
		if (j < 17)
		{
			flag = false;
			printf("%s\n", tmp);
		}
		else
		{
			int Z = last % 11;
			if (z_m[Z] != tmp[17]) 
			{ 
				flag = false;
				printf("%s\n", tmp);
			}
		}
	}

	if (flag == true) { printf("All passed\n"); }
	return 0;
}