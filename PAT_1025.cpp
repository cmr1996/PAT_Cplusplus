#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node
{
	int adress;
	int value;
	int next;
}temp;

int main()
{
	vector<node> vin(100001);
	vector<node> vsort;
	vector<node> vout;

	int first, N, K;//�ڵ��ܸ���N,������K
	cin >> first >> N >> K;
	vin[first].adress = first;
	for (int i = 0; i < N; i++)
	{
		cin >> temp.adress >> temp.value >> temp.next;
		vin[temp.adress] = temp;
	}
	//ȥ����ָ��
	for (int i = 0; i < N; i++)
	{
		if (first==-1)
		{
			//cout << "-1" << endl;
			continue;
		}
		else
		{
			vsort.push_back(vin[first]);
			first = vin[first].next;//ָ����һ��ָ��
		}
	}
	//��vsort�е�������洢��vout��
	int len = vsort.size();

	for (int i = K; i <= len; i+=K)
	{
		for (int j = i-1; j >=i-K; j--)
		{
			vout.push_back(vsort[j]);
		}
	}
	for (int i = (len/K)*K ; i < len; i++)
	{
		vout.push_back(vsort[i]);
	}

	//�޸�nextָ��
	for (int i = 0	; i < len-1; i++)
	{
		vout[i].next = vout[i + 1].adress;
		printf("%05d %d %05d\n", vout[i].adress, vout[i].value, vout[i].next);
	}
	if (len>=1)
	{
		printf("%05d %d -1\n", vout[len - 1].adress, vout[len - 1].value);
	}

	return 0;
}