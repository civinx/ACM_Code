//
//  main.cpp
//  1010: 最小的数
//
//  Created by czf on 15/11/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int n; scanf("%d",&n);
        if (n == -1 && s == "-1") break;
        if (s[0] != '-'){
            int flag = 0;
            for (int i = 0; i < n; i ++){
                int flag = 0;
                for (int j = 0; j < s.length()-1; j ++){
                    int k = 1;
                    if (s[j] != 58){
                        while (s[j+k] == 58) k++;
                        if (s[j] > s[j+k]){
                            s[j] = 58;
                            flag = 1;
                            break;
                        }
                    }
                }
                if (!flag) break;
            }
            int zero = 1, cnt = 0;
            int need = s.length() - n;
            for (int i = 0; cnt < need; i ++){
                if (s[i] != 58 && s[i] != '0'){
                    zero = 0; break;
                }
                if (s[i] != 58) cnt ++;
            }
            if (zero) printf("0\n");
            else{
                cnt = zero = 0;
                for (int i = 0; cnt < need; i ++){
                    if (s[i] != 58 && s[i] != '0') zero = 1;
                    if ((s[i] != 58 && s[i] != '0') || (s[i] == '0' && zero)){
                        printf("%c",s[i]);
                        cnt ++;
                    }
                    else if (s[i] == '0') cnt ++;
                }
                printf("\n");
            }
        }
        else {
            int flag = 0;
            for (int i = 0; i < n; i ++){
                int flag = 0;
                for (int j = 1; j < s.length(); j ++){
                    int k = 1;
                    if (s[j] != 58){
                        while (s[j+k] == 58) k++;
                        if (s[j] < s[j+k]){
                            s[j] = 58;
                            flag = 1;
                            break;
                        }
                    }
                }
                if (!flag) break;
            }
            int need = s.length() - n - 1;
            int cnt = 0;
            printf("-");
            for (int i = 1; cnt < need; i ++){
                if (s[i] != 58){
                    printf("%c",s[i]);
                    cnt ++;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
