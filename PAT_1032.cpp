#include<stdio.h>
#pragma warning(disable:4996);
const int N = 100001;

int main()
{
	int n;
	scanf("%d", &n);
	//��ʼ��
	int score[N];
	int max_grade = 0;//�������ֵ
	int max_index = 0;//���ֵ���λ
	for (int j = 0; j <= n; j++)
	{
		score[j] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		int index, grade;
		scanf("%d %d", &index, &grade);
		score[index] += grade;
		if (score[index] > max_grade)
		{
			max_index = index;
			max_grade = score[index];
		}
	}

	printf("%d %d", max_index, max_grade);
}