//
//  main.c
//  实验8-2-6 分类统计各类字符个数
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];
    
    ReadString(s);
    StringCount(s);
    
    return 0;
}

void StringCount( char *s ){
    int i;
    int daxie = 0;
    int xiaoxie = 0;
    int blank = 0;
    int number = 0;
    int other = 0;
    
    i = 0;
    while (*(s + i) != '\0') {
        if (*(s + i) >= 'A' && *(s + i) <= 'Z') {
            daxie ++;
        }
        else if (*(s + i) >= 'a' && *(s + i) <= 'z') {
            xiaoxie ++;
        }
        else if (*(s + i) >= '0' && *(s + i) <= '9') {
            number ++;
        }
        else if (*(s + i) == ' ') {
            blank ++;
        }
        else{
            other ++;
        }
        i ++;
    }
    printf("%d %d %d %d %d",daxie,xiaoxie,blank,number,other);
}
