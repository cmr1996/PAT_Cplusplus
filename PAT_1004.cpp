#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class student //用类存储学生信息
{
public:
	char name[11];
	char ID[11];
	int score;

	void display();
};

void student::display()//输出方法
{
	cout << name << ' ' << ID << endl;
}

int main()
{
	int std_num; //学生数量
	cin >> std_num;
	student std[std_num];
	student *pstd = &std[std_num];

	for (int i = 0; i<std_num; i++) //开始循环
	{
		cin >> std[i].name;
		cin >> std[i].ID;
		cin >> std[i].score;
	}
	//寻找最好和最坏的成绩的位置
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