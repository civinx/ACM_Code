//
//  main.cpp
//  1101: 数学游戏
//
//  Created by czf on 15/10/20.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int x,n;
        scanf("%d%d",&x,&n);
        if (n%(x+1) == 0) printf("no\n");
        else printf("%d\n",n/(x+1)+1);
    }
    return 0;
}
