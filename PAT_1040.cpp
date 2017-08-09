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
			Tnum++;//T的数量
		}
		else if (*k == 'A') {
			ATnum += Tnum;//AT的数量
		}
		else {//if(*k=='P')
			PATnum += ATnum;//PAT的数量
			if (PATnum > 1000000007){
				PATnum %= 1000000007;
			}				
		}
		k++;
	}
	cout << PATnum;
}