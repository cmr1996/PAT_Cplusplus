#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int str_num;
	cin >> str_num;
	string str;	
	int print_result[11];//����������
	for (int i = 0; i< 11; i++)
		print_result[i] = 2;

	for (int i = 0; i < str_num; i++)
	{
		cin >> str;
		char *temp = (char*)str.data();

		int frontP_A = 0;//pǰA������
		int PtoT_A = 0;//p��t֮��A������
		int behindT = 0;//t��A������
		int Pstart = 0;//p��ʼ���
		int Tstart = 0;//t��ʼ���
		int flag = 0;//�Ƿ�����
		int countP = 0;//p������
		int countT = 0;//t������

		while (*temp!='\0')
		{
			switch (*temp)
			{
			case ' ':
				break;
			case 'A':
				if (Pstart == 0)
				{
					frontP_A++;
				}
				else if ((Pstart == 1) && (Tstart == 0) )
				{
					PtoT_A++;
				}
				else
				{
					behindT++;
				}
				break;
			case 'P':
				Pstart = 1;
				countP++;
				break;
			case 'T':
				Tstart = 1;
				countT++;
				break;
			default:
				flag = 1;
				break;
			}
			temp++;
		}

		if ((frontP_A*PtoT_A==behindT)&&(flag==0) && (PtoT_A >= 1) )
		{
			print_result[i] = 1;
		}
		else
		{
			print_result[i] = 0;
		}
	}

	int i = 0;
	while (print_result[i]!=2)
	{
		if (print_result[i]==1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		i++;
	}
	return 0;
}