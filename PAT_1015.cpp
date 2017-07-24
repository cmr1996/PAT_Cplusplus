#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<set>
using namespace std;

class student
{
public:
	int ID, morality, ability, sum, level;//准考证号,德分,才分,总分,等级(分类)
	student(int ID, int morality, int ability)  {
		this->ID = ID;
		this->morality = morality;
		this->ability = ability;
		this->sum = morality + ability;
		//this->level = level;
		level = 4;//默认分为四类
	}

	bool operator <(const student &another) const  {
		if (level != another.level)
		{
			return another.level < level;
		}
		else if (sum != another.sum)
		{
			return sum < another.sum;//从高到低排序,总值大的在前
		}
		else if (morality != another.morality)
		{
			return morality < another.morality;//从高到低排序,总值大的在前
		}
		//error:else if (ID != another.ID)
		else
		{
			return another.ID < ID;
		}
	}

};

int main()
{
	int N, L, H;//输入总数,最低线,最高线
	cin >> N >> L >> H;

	set<student> Student;
	for (int i = 0; i < N; i++)
	{
		int ID, morality, ability;
		cin >> ID >> morality >> ability;
		student stu(ID, morality, ability);
		if (morality < L || ability <L)
		{
			continue;
		}
		else if (morality >= H && ability >= H)
		{
			stu.level = 1;
		}
		else if (morality >= H)
		{
			stu.level = 2;
		}
		//error:else if (morality < H)
		else if(morality >= ability)
		{
			stu.level = 3;
		}
		else
		{
			stu.level = 4;
		}
		Student.insert(stu);
	}

	//输出结果
	set<student>::reverse_iterator iter;
	cout << Student.size() << endl;
	for ( iter=Student.rbegin() ; iter != Student.rend() ; iter++)
	{
		printf("%d %d %d\n", iter->ID, iter->morality, iter->ability);
		//cout << (*iter).ID << " " << (*iter).morality << " " << (*iter).ability << endl;
	}

	return 0;
}
//所有的c++形式的流式输入输出换成c语言形式的标准输入输出才能通过编译