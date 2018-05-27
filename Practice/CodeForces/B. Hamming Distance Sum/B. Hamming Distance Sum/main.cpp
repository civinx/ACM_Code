//
//  main.cpp
//  B. Hamming Distance Sum
//
//  Created by czf on 15/12/25.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 200000 + 50;
int sum[2][maxn];
int main(){
    string a, b; cin >> a >> b;
    if (a.length() > b.length()) a.swap(b);
    memset(sum,0,sizeof(sum));
    b[0] == '0' ? sum[0][0]++ : sum[1][0]++;
    for(int i = 1; i < b.length(); i ++){
        sum[0][i] = sum[0][i-1] + (b[i]=='0'?1:0);
        sum[1][i] = sum[1][i-1] + (b[i]=='1'?1:0);
    }
    long long res = 0;
    int la = a.length(), lb = b.length();
    for(int i = 0; i < a.length(); i ++){
        if (a[i] == '0')
            if (i) res += sum[1][lb-la+i]-sum[1][i-1];
            else res += sum[1][lb-la+i];
        else
            if (i) res += sum[0][lb-la+i]-sum[0][i-1];
            else res += sum[0][lb-la+i];
    }
    printf("%lld\n",res);
    return 0;
}
