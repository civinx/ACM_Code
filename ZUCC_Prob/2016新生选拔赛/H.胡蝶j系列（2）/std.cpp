#include<iostream>
int main (void)
{
    int t, kase = 0;
    std::cin>>t;
    while(t--)
    {
        int a;
        std::cin>>a;
        a --;
        int b=0;
        while(a)
        {
            b++;
            a>>=1;
        }
        std::cout<< "Case #" << ++kase << ": " << b << '\n';
    }
} 
