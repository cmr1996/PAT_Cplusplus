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

bool cmp(P p1, P p2) {	//��ߴ�С���� �����ֵ���Ӵ�С 
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


	ave = n / k;	//�� 


	string line = "";
	string kk = " ";
	for (int i = 0; i<k; i++) {
		int begin = i*ave;
		int end = i*ave + ave - 1;
		if (end + ave >= n) {	//ʣ�µ��˲�����һ�У�
			end = n - 1;	//������һ��  
		}
		line = p[end].name;	//�м���� 

		for (int j = end - 1; j >= begin; j--) {	//�Ӵ�С���� 
			if (j % 2 != end % 2) {
				line = p[j].name + kk + line;	//��� 
			}
			else {
				line = line + kk + p[j].name;	//�ұ� 
			}
		}
		ans = line + "\n" + ans;
	}
	cout << ans;

	return 0;
}