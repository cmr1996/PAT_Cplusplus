#include<iostream>
#include<string>
using namespace std;
//涂色思想---相同就都消去
int main()
{
	string tmp1, tmp2;

	getline(cin, tmp1); 
	getline(cin, tmp2);

	std::string::iterator iter1; std::string::iterator iter2;

	iter1 = tmp1.begin(); iter2 = tmp2.begin();

	while (iter2!=tmp2.end()){
		iter1 = tmp1.begin();
		while (iter1!=tmp1.end()){
			if (*iter1 == *iter2) {//相等就均"着色"
				*iter1 = '*';
				*iter2 = '*';
				break;
			}
			else{
				iter1++;
			}
		}
		iter2++;
	}

	int flag = 0;
	int cnt_less = 0;//主链缺少珠子的计数器
	int cnt_more = 0;//主链富余珠子的计数器
	for (int i = 0; i < tmp2.size(); i++)
	{
		if (tmp2[i] != '*') {
			cnt_less++;
		}
	}

	if (cnt_less==0){
		for (int i = 0; i < tmp1.size(); i++) {
			if (tmp1[i] != '*') {
				cnt_more++;
			}
		}

		cout << "Yes" << " "<< cnt_more;
	}
	else {
		cout << "No" << " " << cnt_less;
	}

	return 0;
}