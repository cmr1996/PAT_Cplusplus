#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> MAX(int* cnt, int size) {//传入数组和数组的大小
	vector<int> ans;
	int flag = 0;
	int pos;
	int* beg = cnt;
	for (int i = 0; i < size; i++) {
		if (*cnt >= flag) {
			flag = *cnt;
			pos = i+1;
		}
		cnt++;
	}
	for (int i = 0; i < size; i++) {
		if (*beg == flag) {
			ans.push_back(i);
		}
		beg++;
	}
	return ans;
}

int main()
{
	string tmp;
	getline(cin, tmp);
	
	int cnt[26];
	for (int i = 0; i < 27; i++) {
		cnt[i] = 0;
	}

	std::string::iterator m = tmp.begin();
	while (m!=tmp.end())
	{
		if (*m >= 'A'&&*m <= 'Z') {
			int l = (*m) - 'A' ;
			cnt[l]++;
		}
		else if (*m >= 'a'&&*m <= 'z') {
			int l = (*m) - 'a' ;
			cnt[l]++;
		}
		m++;
	}
	
	vector<int> rst = MAX(cnt, 26);
	sort(rst.begin(), rst.end());
	int o = rst.front();
	char d = 'a' + o;
	cout << d << ' ' << cnt[o];

	return 0;
}