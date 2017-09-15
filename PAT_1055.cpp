#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;

struct P
{
	int heigh;
	string name;
};

bool cmp(P p1, P p2)//身高从小到大，名字从大到小
{
	if (p1.heigh == p2.heigh)
	{
		return p1.name > p2.name;//a>b是升序排序重载方式
	}
	else
	{
		return p1.heigh < p2.heigh;
	}
}

int main()
{
	int N, K;//总人数，总排数
	
	cin >> N >> K;
	P *p = new P[N];

	for (int i = 0; i < N; i++)
	{
		cin >> p[i].name >> p[i].heigh;
	}
	sort(p, p + N, cmp);
	
	string ans = "";
	string space = " ";
	int block = N / K;//每段长度
	//int last = N - K*block;
	//int i = 0 ;
	int end = 0 ;
	int begin = 0 ;
	for (int i = 0 ; i < K ; i++ )
	{
		string line;
		begin = i*block;
		end = begin + block - 1;
		if ( begin + end >= N  ) { end = N - 1 ; }
		line = p[end].name;
		for (int j = end - 1 ; j >= begin ; j--)
		{
			if (end % 2 == j % 2) { line = line + space + p[j].name; }//左边
			else { line = p[j].name + space + line; }//右边
		}
		ans = line + "\n" + ans;
	}
	cout << ans;
	return 0;
}