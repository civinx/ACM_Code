//
//  main.cpp
//  2586 Y2K Accounting Bug（贪心神题意）
//
//  Created by czf on 16/3/23.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
int main(){
    int s, d;
    int state[13];
    while(scanf("%d%d",&s,&d) == 2){
        memset(state, 0, sizeof(state));
        int cnt_d, cnt_s;
        for(int i = 1; i <= 8; i ++) {
            cnt_d = state[i] + state[i+1] + state[i+2] + state[i+3] + state[i+4];
            cnt_s = 5 - cnt_d;
            while(cnt_d * d <= cnt_s * s){
                for(int j = 4; j >= 0; j --){
                    if (state[i+j] == 0){
                        state[i+j] = 1;
                        cnt_d ++; cnt_s --;
                        break;
                    }
                }
            }
        }
        cnt_d = cnt_s = 0;
        for(int i = 1; i <= 12; i ++){
            if (state[i]) cnt_d ++;
            else cnt_s ++;
        }
        if (cnt_s * s > cnt_d * d) printf("%d\n",cnt_s*s - cnt_d*d);
        else printf("Deficit\n");
    }
    return 0;
}