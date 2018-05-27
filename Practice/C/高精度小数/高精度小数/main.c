//
//  main.c
//  高精度小数
//
//  Created by czf on 15/10/11.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int y;
    scanf("%d/%d",&x,&y);
    int cnt = 0;
    printf("0.");
    int yushu = x;
    int shang;
    while (++cnt <= 200) {
        shang = yushu*10/y;
        yushu = yushu*10%y;
        printf("%d",shang);
        if (yushu == 0) break;
    }
    return 0;
}
