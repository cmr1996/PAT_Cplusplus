#include<stdio.h>

int main()
{
	int xs, zs;//ϵ����ָ��
	int flag_first = 1;//��λ���
	while (scanf("%d%d",&xs,&zs)!=EOF)
	{
		if (flag_first) //flag_firstΪ1��˵�����λ����λ
		{
			if (zs!=0)
			{
				printf("%d %d", xs*zs, zs - 1);//��λ��ӡ"����+�ո�+����"
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