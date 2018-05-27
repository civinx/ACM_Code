#include<iostream> 
int main (void)
{
	int t, kase = 0;
	std::cin>>t;
	while(t--)
	{
		int n,m;
		std::cin>>n>>m;
		if(n-m<m) m = n-m;
		std::cout<< "Case #" << ++kase << ": " << m<< '\n';
	}
} 
