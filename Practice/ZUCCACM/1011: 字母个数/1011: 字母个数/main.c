//
//  main.c
//  1011: 字母个数
//
//  Created by czf on 15/10/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    int t;
    char x;
    int a[27];
    scanf("%d",&t);
    int kase = 0;
    getchar();
    while (t--) {
        memset(a, 0, sizeof(a));
//        scanf("%c",&x);
//        for (int i = 0; x != '\n'; i ++) {
//            if (x >= 'a' && x <= 'z') a[x- 'a'] ++;
//            scanf("%c",&x);
//        }
        
//        while ((x = getchar()) != '\n') {
//            if (x >= 'a' && x <= 'z') a[x- 'a'] ++;
//        }
        
        for (; (x=getchar()) != '\n';) {
            if (x >= 'a' && x <= 'z') a[x- 'a'] ++;
        }
        
        printf("Case %d:\n",++kase);
        int sign = 1;
        for (int i = 0; i < 27; i ++) {
            if (a[i] && sign){
                printf("%c:%d",'a'+i,a[i]);
                sign = 0;
            }
            else if (a[i]) printf(" %c:%d",'a'+i,a[i]);
        }
        printf("\n");
    }
    return 0;
}
