#include<iostream> 
int main (void)
{
	int t;
	std::cin>>t;
	while(t--)
	{
		int a,b;
		std::cin>>a>>b;
		if(a-b<b) b = a-b;
		std::cout<<b<<'\n';
	}
} 
