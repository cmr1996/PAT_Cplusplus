#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string **num = new string*[N];
	vector<double> legalnum;
	vector<int> illegal_location;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		int LEN = tmp.length();
		num[i] = new string[LEN];//��̬�����ڴ�
		*num[i] = tmp;

		int isNumber = 1;//���ݺϷ��Ա��λ
		int dot = 0;
		int dot_ = 0;//С�����λ��
		std::string::iterator point = tmp.begin();
		for (int j = 0; point != tmp.end(); point++, j++){
			if (dot == 1) { dot_++; }
			if (*point == '-'&&j != 0) { isNumber = 0; break; }
			if (*point != '.'){
				if ((*point<'0'||*point>'9')&&*point != '-'){
					isNumber = 0;
					break;
				}
				else{
					isNumber = 1;
				}
			}
			else{
				dot++;
			}
			if (dot >= 2||dot_>2) { 
				isNumber = 0;
				break;
			}
		}
		if (!isNumber) { illegal_location.push_back(i); }
		else {
			stringstream ss;
			ss << tmp;
			double tmpnum;
			ss >> tmpnum;
			if ((double)-1000 > tmpnum || tmpnum > (double)1000) {
				illegal_location.push_back(i);
				}	
			else {
				legalnum.push_back(tmpnum);
				}
		}
	}

	//����Ƿ���Ϣ
	int illegal_len = illegal_location.size();
	if (illegal_len!=0)
	{
		for (int i = 0; i < illegal_len; i++) {
			int j = illegal_location[i];
			cout << "ERROR:" << " " << *num[j] << " " << "is not a legal number" << endl;
		}
	}

	//����Ϸ���Ϣ
	int ans_len = legalnum.size();
	if (ans_len == 0) {
		cout << "The average of 0 numbers is Undefined" << endl;
	}
	else if (ans_len == 1) {
		cout << "The average of 1 number is " << fixed << setprecision(2) << legalnum[0] << endl;
	}
	else {
		double sum = 0;
		for (int i = 0; i < ans_len; i++)
		{
			sum += legalnum[i];
		}
		double ans = sum / ans_len;
		cout << "The average of" << ' ' << ans_len << " numbers is " << fixed << setprecision(2) << ans << endl;
	}//���⻹��Ҫϸ�ģ�����һ������ƽ��ֵ����������һ����1

	return 0;	
}