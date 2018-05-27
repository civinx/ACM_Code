#include<stdio.h>
int main ()
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int a,b;
		scanf("%d%d",&a,&b); 
		printf("Case #%d: %d\n",cas,((b>>1)|a)+(b>>1));
	}
	return 0;
} 
