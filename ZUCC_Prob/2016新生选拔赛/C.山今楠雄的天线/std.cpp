#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int __gcd(int a, int b)
{
	return b ? (__gcd(b,a%b)):a;
}
int main()
{
	int T, p, q, N;
	scanf("%d", &T);
	for(int ti = 1;ti <= T;ti++)
	{
		scanf("%d%d%d", &N, &p, &q);
		int a = (int)(N / p);
		int b = (int)(N / q);
		int tmp = p*q / (__gcd(p, q));
		int c = (int)(N / tmp);
		printf("Case #%d: %d\n", ti, N - a - b + 2 * c);
	}
	return 0;
}
