//
//  main.cpp
//  2048 神、上帝以及老天爷
//
//  Created by czf on 15/12/22.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    double s[30], a[30];
    s[1] = 1; s[2] = 2;
    for(int i = 3; i < 30; i ++) s[i] = s[i-1]+s[i-1]*(i-1);
    a[1] = 0; a[2] = 1;
    for(int i = 3; i < 30; i ++) a[i] = (i-1)*(a[i-1]+a[i-2]);
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        printf("%.2f%%\n",a[n]/s[n]*100);
    }
    return 0;
}
