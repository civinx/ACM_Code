//
//  main.cpp
//  Problem : Convert QWERTY to Dvorak
//
//  Created by czf on 16/4/18.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

char s1[]= {"-=_+qwertyuiop[]QWERTYUIOP{}asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?"};
char s2[]= {"[]{}',.pyfgcrl/=\"<>PYFGCRL?+aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ"};
char c;

char print(char c)
{
    for(int i=0; s1[i]; i++)
        if(s1[i]==c)
            return s2[i];
    return c;
}
int main(){
    while (~scanf("%c",&c))
        printf("%c",print(c));
    return 0;
}