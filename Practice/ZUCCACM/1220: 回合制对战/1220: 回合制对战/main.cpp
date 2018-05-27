//
//  main.cpp
//  1220: 回合制对战
//
//  Created by czf on 15/11/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int a_hp, a_atk, b_hp, b_atk;
    while(scanf("%d%d%d%d",&a_atk,&a_hp,&b_atk,&b_hp) == 4){
        if(!a_atk && !b_atk){
            printf("Draw\n");
            continue;
        }
        else if (!a_atk){
            printf("Lost\n");
            continue;
        }
        else if (!b_atk){
            printf("Win\n");
            continue;
        }
        int cnt1 = a_hp / b_atk;
        int cnt2 = b_hp / a_atk;
        if (a_hp % b_atk != 0) cnt1++;
        if (b_hp % a_atk != 0) cnt2++;
        if(cnt1 > cnt2) printf("Win\n");
        else if(cnt1 < cnt2) printf("Lost\n");
        else printf("Draw\n");
    } 
    return 0;
}

