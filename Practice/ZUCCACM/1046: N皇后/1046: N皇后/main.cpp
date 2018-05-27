//
//  main.cpp
//  1046: N皇后
//
//  Created by czf on 15/10/27.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    int n;
    while (cin >> n) {
        string a, b;
        stringstream ss;
        a = "1";
        for (int i = 1; i <= n; i ++) {
            int carry = 0;
            for (int j = a.length()-1; j >= 0; j --) {
                ss.clear();
                ss << ((a[j]-'0') * i + carry) % 10;
                carry = ((a[j]-'0') * i + carry) / 10;
                ss >> a[j];
                if (!j && carry) {
                    ss.clear();
                    ss << carry;
                    ss >> b;
                    a = b + a;
                }
            }
        }
        cout << a << '\n';
    }
}



//#include <stdio.h>
//#include <string.h>
//int ans[30];
//double tot;
//
//void search (int cur, int n){
//    if (cur == n) tot ++;
//    else for(int i = 0; i < n; i ++){
//        if (!ans[i]){
//            ans[i] = 1;
//            search(cur+1, n);
//            ans[i] = 0;
//        }
//    }
//}
//
//int main() {
//    int n;
//    while (scanf("%d",&n) != EOF) {
//        tot = 0;
//        memset(ans, 0, sizeof(ans));
//        search(0, n);
//        printf("%.f\n",tot);
//    }
//    return 0;
//}
