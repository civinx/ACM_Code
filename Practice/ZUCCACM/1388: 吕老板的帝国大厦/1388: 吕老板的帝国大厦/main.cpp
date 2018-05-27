//
//  main.cpp
//  1388: 吕老板的帝国大厦
//
//  Created by czf on 15/11/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        if (n%3==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
