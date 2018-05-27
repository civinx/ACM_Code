#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
int i,j,k,l,n,m,s,an,K,X,tot=1,oo,sum;
int main()
{
	srand(time(0));
	freopen("a.in","w",stdout);
	int T=rand()%50+1;
	T=30;
	printf("%d\n",T);
	while (T--)
	{
		int r=rand()%1000;
    	for (int i=1;i<=2;i++)
    	printf("%d %d %d\n",rand()%1000,rand()%1000,r);
    }
	return 0;
}
