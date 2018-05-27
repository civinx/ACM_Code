//
//  main.c
//  1571: 路痴的某楠
//
//  Created by czf on 15/10/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include<stdio.h>
#define maxn 30
int main(){
    int south[maxn],ws[maxn];
    south[0] = 1;
    ws[0] = 1;
    for(int i = 1; i <= 25; i ++){
        ws[i] = ws[i - 1] + south[i - 1];
        south[i] = ws[i - 1] * 2 + south[i - 1];
    }
    int t;
    scanf("%d",&t);
    while(t -- ){
        int n;
        scanf("%d",&n);
        printf("%d\n",south[n-1] + ws[n - 1] * 2);
    }
}

//#include<iostream>
//using namespace std;
//
//void dfs(int n);
//
//int a[30];
//int res[30];
//
//int main(){
//    dfs(1);
//    for (int i = 1; i <= 24; i ++) {
//        cout << res[i-1] << ',';
//    }
//    return 0;
//}
//
//void dfs(int n){
//    if (n > 24) {
//        return;
//    }
//    else{
//        for (int i = 1; i < 4; i ++) {
//            a[n] = i;
//            if (n != 1 && ((a[n-1] == 2 && a[n] == 3) || (a[n-1] == 3 && a[n] == 2))) {
//                continue;
//            }
//            res[n] ++;
//            dfs(n+1);
//            a[n] = 0;
//        }
//    }
//}