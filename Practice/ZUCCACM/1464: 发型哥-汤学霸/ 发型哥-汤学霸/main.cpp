//
//  main.cpp
//   发型哥-汤学霸
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a[5];
    int t;
    scanf("%d",&t);
    while (t--) {
        for (int i = 0; i < 5 ; i ++) scanf("%d",&a[i]);
        sort(a,a+5);
        int x;
        scanf("%d",&x);
        if (a[2] == x) {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}