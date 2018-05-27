//
//  main.cpp
//  字符串逆序
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
using namespace std;
int main(){
    int t;
    char a[80];
    scanf("%d",&t);
    getchar();
    while (t--) {
        gets(a);
        int n = strlen(a);
        for (int i = n-1; i >= 0; i --) printf("%c",a[i]);
        printf("\n");
    }
}