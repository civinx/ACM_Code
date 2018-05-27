//
//  main.cpp
//  1108: 称出假珍珠Ⅱ
//
//  Created by czf on 16/2/23.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        printf("%.f\n",(pow(3,n)-1)/2);
    }
    return 0;
}