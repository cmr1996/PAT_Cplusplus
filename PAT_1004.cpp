#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class student //����洢ѧ����Ϣ
{
public:
	char name[11];
	char ID[11];
	int score;

	void display();
};

void student::display()//�������
{
	cout << name << ' ' << ID << endl;
}

int main()
{
	int std_num; //ѧ������
	cin >> std_num;
	student std[std_num];
	student *pstd = &std[std_num];

	for (int i = 0; i<std_num; i++) //��ʼѭ��
	{
		cin >> std[i].name;
		cin >> std[i].ID;
		cin >> std[i].score;
	}
	//Ѱ����ú���ĳɼ���λ��
	int best_pos = 0;
	int worst_pos = 0;

	for (int j = 1; j < std_num; j++)
	{
		if (std[j].score>std[best_pos].score)
		{
			best_pos = j;
		}
		if (std[j].score < std[worst_pos].score)
		{
			worst_pos = j;
		}
	}

	std[best_pos].display();
	std[worst_pos].display();

	return 0;
}