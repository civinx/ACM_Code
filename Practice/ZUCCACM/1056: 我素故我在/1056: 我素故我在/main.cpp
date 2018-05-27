//
//  main.cpp
//  1056: 我素故我在
//
//  Created by czf on 15/11/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
//using namespace std;
//const int maxn = 100000000 + 5;
//bool a[maxn];
int main() {
    int t;
    int a[8][20] = {{2,3,5,7},{23,29,31,37,53,59,71,73,79},{233,239,293,311,313,317,373,379,593,599,719,733,739,797},{2333,2339,2393,2399,2939,3119,3137,3733,3739,3793,3797,5939,7193,7331,7333,7393},{23333,23339,23399,23993,29399,31193,31379,37337,37339,37397,59393,59399,71933,73331,73939},{233993,239933,293999,373379,373393,593933,593993,719333,739391,739393,739397,739399},{2339933,2399333,2939999,3733799,5939333,7393913,7393931,7393933},{23399339,29399999,37337999,59393339,73939133}};
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        for (int i = 0; a[n-1][i] != 0; i ++) {
            printf("%d\n",a[n-1][i]);
        }
    }
    return 0;
}
//    for (int i = 3; i < maxn; i += 2) {
//        a[i] = true;
//    }
//    a[2] = true;
//    int t = (int)sqrt(maxn*1.0);
//    for (int i = 3; i <= t; i ++) {
//        if (a[i]){
//            for (int j = i+i; j < maxn; j += i) {
//                a[j] = false;
//            }
//        }
//    }
//    for (int i = 2; i < maxn; i ++) {
//        int flag = 1;
//        int temp = i;
//        while (temp) {
//            if (a[temp] == false) {
//                flag = 0;
//                break;
//            }
//            temp /= 10;
//        }
//        if (flag) printf("%d,",i);
//    }
//    
//    return 0;
//}
