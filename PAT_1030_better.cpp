#pragma warning(disable:4996);
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	long N, P;//输入的总数N和给定的参数P
	scanf("%d %d", &N, &P);
	int num[100001];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	sort(num, num + N);

	int m = 0;
	for (long i = 0; i < N; i++)
	{
		for (long j = i+m; j < N; j++)
		{
			//long tmp = num[i] * P;
			if(num[j]>num[i] * P)
			{
				break;
			}
			m++;
		}
	}

	printf("%d", m);
	return 0;
}

//最后一个测试点通不过的原因是i,j,N,P没有使用long整形


/*思路：首先p与最小数相乘可能会超出int范围，所以这里用double,
其次我们应该先将数组排序以方便计算，然后我们用双重for循环查找，
查找的思路是从第一个元素作为最小数，开始往后找最大数，直到不符合条件，
记录下此时的长度，然后将第二个元素作为最小数，再继续找，
最后比较长度的最大值并输出，但是这样会超时，所以我们要对她进行优化，
减少不必要的循环，优化的思路如下：

首先我们同样保持第一个for循环遍历最小值，
在第二个for循环中我们将j置为前一个元素作为最小数时候的长度，
这样就减少了小于上一次的不必要的for循环，j依然小于 N，
用一个if判断是否符合条件，用另一个if判断此次是否大于上次的长度，
比如说我们把样例中的数据已经排好序：1 2 3 4 5 6 7 8 9 20 ，
此时我们将array[0]作为最小数，依次向后遍历，
最大数j-最小数i+1即为数列的长度，最终找到8为最大的数，
此时数列长度count为8，在将a[1]作为最小数的时候，
我们直接将j置为1+8为9，
直接比较a[1]和a[9]作为最小最大值得时候是否满足，
不满足则a[1]最为最小数的时候并不能使数列变得更长，
则继续再看a[2],这样等到有大于8的时候再更新，就可以了。*/
//分析来自http://blog.csdn.net/wanmeiwushang/article/details/51456488