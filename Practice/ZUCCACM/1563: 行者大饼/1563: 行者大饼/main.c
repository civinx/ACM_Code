//
//  main.c
//  1563: 行者大饼
//
//  Created by czf on 15/10/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main() {
    int zushu;
    int z;
    int M,N;
    int i;
    int last;
    char a[101];
    int guoshi;
    int buff;
    int flag_dead = 0;
    int flag_pass = 0;
    int flag_fail = 0;
    int flag_fail_1 = 0;
    
    scanf("%d",&zushu);
    
    for (z = 0; z < zushu; z ++) {
        scanf("%d %d",&N,&M);
        
        scanf("%s",a);
        
        last = M - 1; //此时last为最后一个字母的下标
        
        buff = 0;
        flag_dead = 0;
        flag_pass = 0;
        flag_fail = 0;
        guoshi = 0;
        
        for (i = 0; a[i] != '\0'; i++) {
            if (a[i] == 'F') {
                guoshi ++;
                
            }
            else if (a[i] == 'W'){
                if (guoshi > 0) {
                    guoshi /= 2;
                    buff = 1;
                }
                if (buff == 1) {
                    buff = 0;
                }
                else{
                    flag_dead = 1;
                    break;
                }
            }
        }
        if (guoshi > N && flag_dead == 0) {
            flag_pass = 1;
        }
        if(guoshi <= N && flag_dead == 0){
            flag_fail = 1;
        }//第一条路循环到这
        
        if ((flag_fail || flag_dead) && flag_pass == 0) {
            buff = 0;
            flag_dead = 0;
            flag_pass = 0;
            flag_fail_1 = 0;
            guoshi = 0;
            for (i = last; i >= 0; i --) {
                if (a[i] == 'F') {
                    guoshi ++;
                }
                else if (a[i] == 'W'){
                    if (guoshi > 0) {
                        guoshi /= 2;
                        buff = 1;
                    }
                    if (buff == 1) {
                        buff = 0;
                    }
                    else{
                        flag_dead = 1;
                        break;
                    }
                }
            }//第二条路循环到这
            if (guoshi > N && flag_dead == 0) {
                flag_pass = 1;
            }
            if(guoshi <= N && flag_dead == 0){
                flag_fail_1= 1;
            }
        }
        if (flag_pass) {
            printf("Pass\n");
        }
        else if (flag_fail || flag_fail_1){
            printf("Fail\n");
        }
        else if (flag_dead){
            printf("Dead\n");
        }
    }
    return 0;
}
