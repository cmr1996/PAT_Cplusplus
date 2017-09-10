#include<iostream>
#include<stdio.h>
#define MAX 5 //row
#define MAX_CH 11 //line
using namespace std;

int read_exp(char array[][MAX]) {
	int i = 0, j = 0, flag = 0;
	char tmp;
	while ((tmp = getchar()) != '\n') {
		if (tmp == '[' && !flag) {
			j = 0; 
			flag = 1; 
		}
		else if (tmp == ']'&&flag) { 
			array[i][j] = '\0'; 
			i++; 
			flag = 0; 
		}
		else if (flag) { 
			array[i][j++] = tmp; }
	}
	return i ;
}

int main()
{
	char hands[MAX_CH][MAX], eyes[MAX_CH][MAX], mouths[MAX_CH][MAX];
	int handcnt, eyecnt, mouthcnt;
	handcnt = read_exp(hands);
	eyecnt = read_exp(eyes);
	mouthcnt = read_exp(mouths);

	int lhand, leye, mouth, reye, rhand;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> lhand >> leye >> mouth >> reye >> rhand;
		if (lhand<1 || lhand>handcnt || rhand<1 || rhand>handcnt) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		if (leye<1 || leye>eyecnt || reye<1 || reye>eyecnt) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
		if (mouth<1 || mouth>mouthcnt) {
			cout << "Are you kidding me? @\\/@" << endl;
			continue;
		}
	printf("%s(%s%s%s)%s\n", hands[lhand - 1], eyes[leye - 1], mouths[mouth - 1], eyes[reye - 1], hands[rhand - 1]);
	}
	return 0;

}