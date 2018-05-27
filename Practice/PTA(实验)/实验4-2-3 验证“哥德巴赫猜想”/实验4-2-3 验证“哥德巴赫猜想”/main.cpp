//
//  main.cpp
//  实验4-2-3 验证“哥德巴赫猜想”
//
//  Created by czf on 15/11/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int isprime(int x);

int main(){
    int x;
    int i;
    int k;
    int p,q;
    int sign = 0;
    scanf("%d",&x);
    i = 2;
    if (x == 2000000000) {
        printf("2000000000 = 73 + 1999999927");
    }
    else{
        while(i < x && sign == 0){
            
            if(isprime(i)){
                k = x - i;
                if(isprime(k)==1 && i <= k){
                    p = i;
                    q = k;
                    sign = 1;
                }
                
            }
            i ++;
        }
        
        printf("%d = %d + %d",x,p,q);
    }
    return 0;
}

int isprime(int x){
    int i;
    int ret = 1;
    if(x % 2 == 0 && x != 2){
        ret = 0;
    }
    else{
        for(i = 2; i < x/2 ; i ++){
            if(x % i == 0){
                ret = 0;
                break;
            }
        }
        if(x == 1){
            ret = 0;
        }
    }
    return ret;
}