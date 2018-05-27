//
//  main.cpp
//  1008 Elevator
//
//  Created by czf on 15/11/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int n;
    while(scanf("%d",&n) == 1 && n){
        int x,beg = 0, sum = 0;
        while(n--){
            scanf("%d",&x);
            if (x > beg)
                sum += (x-beg) * 6;
            else
                sum += (beg-x) * 4;
            sum += 5;
            beg = x;
        }
        printf("%d\n",sum);
    }
}
