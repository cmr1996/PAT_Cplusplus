#include<iostream>
#include<string>
#include<sstream>
#include<algorithm> //std::equal
using namespace std;

int IsSame(string tmp1, string tmp2)
{
	int flag = 1;
	for (int i = 0; i < tmp1.length(); i++)
	{
		if (tmp1[i] != tmp2[i]) { flag = 0;
		break;
		}
	}
	if (flag){
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	string low[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
	string high[13] = { "null","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
	string input;
	string IN[100];
	int N;
	int num = 0;
	cin >> N;	
	cin.clear();
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, IN[i]);
	}

	for (int i = 0; i < N; i++)
	{
		input = IN[i];
		if (input[0] >= '0'&&input[0] <= '9')
		{
			int h, l;
			stringstream ss;
			ss << input;
			ss >> num;
			if (num >= 13) { 
				if (num % 13 == 0) {
					cout << high[num / 13] << endl;
				}
				else {
					cout << high[num / 13] << " " << low[num % 13] << endl;
				}

			}
			else
			{
				cout << low[num] << endl;
			}
		}
		else
		{
			if (input.size() < 4)
			{
				int tmp;
				for (int j = 0; j < 13; j++)
				{
					if (IsSame(input, low[j])) {
						tmp = j;//相等返回地球文
						break;
					}
					else if (IsSame(input, high[j])) {
						tmp = j * 13;
						break;
					}
				}
				cout << tmp << endl;
			}
			else
			{
				int tmp = 0;
				for (int i = 0; i < 13; i++)
				{
					if (std::equal(input.begin(), input.begin() + 3, high[i].begin()))
					{
						tmp = 13 * i;
						break;
					}
				}
				for (int i = 0; i < 13; i++)
				{
					if (std::equal(input.begin() + 4, input.end(), low[i].begin())) {
						tmp += i;
						break;
					}
				}
				cout << tmp << endl;
			}
		}
	}

	return 0;
}