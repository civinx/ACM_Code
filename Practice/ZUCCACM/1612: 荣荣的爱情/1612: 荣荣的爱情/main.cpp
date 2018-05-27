//
//  main.cpp
//  1612: 荣荣的爱情
//
//  Created by czf on 15/12/21.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
struct day{
    int m;
    int d;
};
int main(){
    int t; scanf("%d",&t);
    while(t--){
        day x[10]; int ans[10]; int prt[2];
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < 10; i ++) scanf("%d%d",&x[i].m,&x[i].d);
        for(int i = 0; i < 10; i ++){
            for(int j = 0; j < 10; j ++){
                if(x[j].d == x[i].d) ans[i] ++;
            }
        }
        int know, kase; scanf("%d%d",&know,&kase);
        int flag = 0; int res = 0;
        if (kase == 1){
            for(int i = 0; i < 10;){
                flag = 1;
                int temp = x[i].m;
                int j = i;
                for(;x[i].m==temp;i++){
                    if (ans[i] < 2) flag = 0;
                }
                if (flag){
                    for(;x[j].m==temp;j++){
                        if (x[j].d==know){
                            prt[0] = x[j].m;
                            prt[1] = x[j].d;
                            res += 1;
                        }
                    }
                }
            }
        }
        else{
            for(int i = 0; i < 10;){
                flag = 0;
                int temp = x[i].m;
                int j = i;
                for(;x[i].m==temp;i++){
                    if (ans[i] == 1) flag = 1;
                }
                if (flag){
                    for(;x[j].m==temp;j++){
                        if (x[j].d==know){
                            res += 1;
                            prt[0] = x[j].m;
                            prt[1] = x[j].d;
                        }
                    }
                }
            }
        }
        if (res == 1) printf("%d %d\n",prt[0],prt[1]);
        else printf("Sorry, I can't know.\n");
    }
    return 0;
}