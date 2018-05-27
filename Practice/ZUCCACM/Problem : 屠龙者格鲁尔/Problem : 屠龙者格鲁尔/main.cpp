//
//  main.cpp
//  Problem : 屠龙者格鲁尔
//
//  Created by czf on 15/12/24.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; double p; scanf("%d%lf",&n,&p);
        double f = 0;
        for(int i = 7; i < n; i ++){
            if (i == 7) f = 1;
            else f += 1/(1-p);
        }
        printf("%.4f\n",f);
    }
    return 0;
}