#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int main()
{
	string not_exist;
	string complete;
	string answer;
	getline(cin, not_exist);
	getline(cin, complete);
	
	int CAPS_flag = 0;
	int len1 = not_exist.size();
	int len2 = complete.size();
	//�ж��ϵ����Ƿ��ǻ���
	std::size_t f = not_exist.find("+");
	if (f!=std::string::npos)
	{
		CAPS_flag = 1;
	}

	for (int i = 0; i < len2; i++)
	{
		char tmp = complete[i];
		//����ϵ����𻵲����д�д��ĸ,��ô��������ĸд��answer
		if ((tmp>='A'&&tmp<='Z')&&CAPS_flag==1)
		{
			continue;
		}
		if (tmp>='a'&&tmp<='z')
		{
			tmp = tmp - 'a' + 'A';
		}
		std::size_t found = not_exist.find(tmp);
		if (found==std::string::npos)
		{
			answer.push_back(complete[i]);
		}
	}
	//�ж��ַ����Ƿ�Ϊ��
	if (answer.empty())
	{
		cout << endl;
	}
	else
	{
		cout << answer;
	}
	return 0;
}

//��Ŀ����˼�ǽ��üӺŴ����ϵ�������Ҫע��!!!!!