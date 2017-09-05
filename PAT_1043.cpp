#include<iostream>
#include<string>
using namespace std;

int main()
{
	string tmp;
	getline(cin, tmp);
	int P = 0, A = 0, T = 0, e = 0, s = 0, t = 0;
	for (std::string::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
	{
		if (*iter == 'P') { P++; }
		if (*iter == 'A') { A++; }
		if (*iter == 'T') { T++; }
		if (*iter == 'e') { e++; }
		if (*iter == 's') { s++; }
		if (*iter == 't') { t++; }
	}

	int cnt = P + A + T + e + s + t;
	while (cnt!=0)
	{
		if (P != 0) { cout << 'P'; P--; }
		if (A != 0) { cout << 'A'; A--; }
		if (T != 0) { cout << 'T'; T--; }
		if (e != 0) { cout << 'e'; e--; }
		if (s != 0) { cout << 's'; s--; }
		if (t != 0) { cout << 't'; t--; }
		cnt = P + A + T + t + e + s;
	}
	return 0;
}