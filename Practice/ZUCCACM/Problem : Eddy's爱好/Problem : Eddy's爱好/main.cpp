//
//  main.cpp
//  Problem : Eddy's爱好
//
//  Created by czf on 16/3/29.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
typedef long long ll;
const double pri[17] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
const double pri_2[17] = {6,10,14,15,21,22,26,33,34,35,38,39,46,51,55,57,58};

int main() {
    double n;
    while(~scanf("%lf",&n)) {
        int res = 0;
        for(int i = 0; i < 17; i ++) {
            int ans = (int)pow(n,1/pri[i]);
            if (ans == 1) break;
            res += ans - 1;
        }
        res ++;
        for(int i = 0; i < 17; i ++) {
            int ans = (int)pow(n,1/pri_2[i]);
            if (ans == 1) break;
            res -= ans - 1;
        }
        if (n >= pow(2,30)) res ++;
        if (n >= pow(2,42)) res ++;
        if (n >= pow(3,30)) res ++;
        printf("%d\n",res);
    }
    return 0;
}