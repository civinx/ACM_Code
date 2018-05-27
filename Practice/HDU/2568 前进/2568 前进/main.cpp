//
//  main.cpp
//  2568 前进
//
//  Created by czf on 15/11/24.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, res = 0;
        scanf("%d",&n);
        while(n){
            if (n%2) {
                res ++;
                n--;
            }
            else n /= 2;
        }
        printf("%d\n",res);
    }
    return 0;
}
