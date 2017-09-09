#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

//368782971
//    1234567
//101010101

//采用前端补零法
int main()
{
	char A[101], A_res[101];
	char B[101], B_res[101];
	char ans[101];
	int Alen, Blen;
	cin >> A >> B;
	Alen = strlen(A); Blen = strlen(B);
	int max = Alen > Blen ? Alen : Blen;
	int i, j;
	//将A反转并补零
	for (i = Alen - 1, j = 0; i >= 0; i--, j++) {
		A_res[j] = A[i];
	}
	for (; j < max; j++) {
		A_res[j] = '0';
	}

	//将B反转并补零
	for (i = Blen - 1, j = 0; i >= 0; j++, i--) {
		B_res[j] = B[i];
	}
	for (; j < max; j++) {
		B_res[j] = '0';
	}

	int flag = 1;
	for (int i = 0; i < max; i++) {
		if (flag) {
			int k = (A_res[i] - '0' + B_res[i] - '0') % 13;
			switch (k)
			{
			case 10:
				ans[i] = 'J'; break;
			case 11:
				ans[i] = 'Q'; break;
			case 12:
				ans[i] = 'K'; break;
			default:
				ans[i] = k + '0';
				break;
			}
			flag = 0;
		}
		else {
			int k = B_res[i] - A_res[i] >= 0 ? B_res[i] - A_res[i] : B_res[i] - A_res[i] + 10;
			flag = 1;
			ans[i] = k + '0';
		}
	}

	for (int i = max - 1; i >= 0; i--) {
		cout << ans[i];
	}
}