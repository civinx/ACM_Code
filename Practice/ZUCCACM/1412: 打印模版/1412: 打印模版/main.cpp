//
//  main.cpp
//  1412: 打印模版
//
//  Created by czf on 15/12/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int n, m;
    while(scanf("%d%d",&n,&m) == 2){
        int temp = m, cnt = 1;
        for(int i = 0; i < n; i ++){
            int x; scanf("%d",&x);
            if (temp >= x){
                temp -= x;
            }
            else{
                cnt ++;
                temp = m-x;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}