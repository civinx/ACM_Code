//
//  main.cpp
//  1456: 手心手背
//
//  Created by czf on 15/11/12.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>

int main() {
    int x, y, z;
    while (scanf("%d%d%d",&x,&y,&z) == 3) {
        if (x-y-2*z>=0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
