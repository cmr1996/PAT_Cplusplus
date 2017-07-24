#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<set>
using namespace std;

class student
{
public:
	int ID, morality, ability, sum, level;//׼��֤��,�·�,�ŷ�,�ܷ�,�ȼ�(����)
	student(int ID, int morality, int ability)  {
		this->ID = ID;
		this->morality = morality;
		this->ability = ability;
		this->sum = morality + ability;
		//this->level = level;
		level = 4;//Ĭ�Ϸ�Ϊ����
	}

	bool operator <(const student &another) const  {
		if (level != another.level)
		{
			return another.level < level;
		}
		else if (sum != another.sum)
		{
			return sum < another.sum;//�Ӹߵ�������,��ֵ�����ǰ
		}
		else if (morality != another.morality)
		{
			return morality < another.morality;//�Ӹߵ�������,��ֵ�����ǰ
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
	int N, L, H;//��������,�����,�����
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

	//������
	set<student>::reverse_iterator iter;
	cout << Student.size() << endl;
	for ( iter=Student.rbegin() ; iter != Student.rend() ; iter++)
	{
		printf("%d %d %d\n", iter->ID, iter->morality, iter->ability);
		//cout << (*iter).ID << " " << (*iter).morality << " " << (*iter).ability << endl;
	}

	return 0;
}
//���е�c++��ʽ����ʽ�����������c������ʽ�ı�׼�����������ͨ������