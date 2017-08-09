#include<iostream>
#include<string>
using namespace std;

int main()
{
	string tmp;
	getline(cin, tmp);
	
	std::string::reverse_iterator k = tmp.rbegin() ;
	
	int ATnum = 0, PATnum = 0, Tnum = 0;
	while ( k!=tmp.rend() )
	{
		if (*k == 'T') {
			Tnum++;//T������
		}
		else if (*k == 'A') {
			ATnum += Tnum;//AT������
		}
		else {//if(*k=='P')
			PATnum += ATnum;//PAT������
			if (PATnum > 1000000007){
				PATnum %= 1000000007;
			}				
		}
		k++;
	}
	cout << PATnum;
}