#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, k;
int last, ave;
string ans = "";
struct P {
	string name;
	int heigh;
};

bool cmp(P p1, P p2) {	//身高从小到大 名字字典序从大到小 
	if (p1.heigh != p2.heigh) {
		return p1.heigh<p2.heigh;
	}
	else {
		return p1.name>p2.name;
	}

}

int main() {

	scanf("%d%d", &n, &k);
	P p[n];
	for (int i = 0; i<n; i++) {
		cin >> p[i].name >> p[i].heigh;
	}
	sort(p, p + n, cmp);


	ave = n / k;	//行 


	string line = "";
	string kk = " ";
	for (int i = 0; i<k; i++) {
		int begin = i*ave;
		int end = i*ave + ave - 1;
		if (end + ave >= n) {	//剩下的人不够再一行，
			end = n - 1;	//补到这一行  
		}
		line = p[end].name;	//中间最大 

		for (int j = end - 1; j >= begin; j--) {	//从大到小排列 
			if (j % 2 != end % 2) {
				line = p[j].name + kk + line;	//左边 
			}
			else {
				line = line + kk + p[j].name;	//右边 
			}
		}
		ans = line + "\n" + ans;
	}
	cout << ans;

	return 0;
}