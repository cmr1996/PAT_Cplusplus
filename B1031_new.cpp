#pragma warning (disable:4996)
#include<cstdio>
#include<cstring>
//Ȩֵ
int w[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
//У����
char z_m[11] = { '1','0','X','9','8','7','6','5','4','3','2' };

int main()
{
	int n;
	int sum = 0;//��ȷ����
	bool flag = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char tmp[18];
		int last = 0;
		scanf("%s", tmp);
		int j = 0;
		for (; j < 17; j++)
		{   //���ֲ��Ϸ����־ͽ�������ѭ��
			if (tmp[j]<'0' || tmp[j]>'9') { break; }//break��������ѭ����
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