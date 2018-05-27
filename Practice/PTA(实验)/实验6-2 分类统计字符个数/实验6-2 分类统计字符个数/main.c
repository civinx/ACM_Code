//
//  main.c
//  实验6-2 分类统计字符个数
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXS 15

void StringCount( char s[] );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];
    
    ReadString(s);
    StringCount(s);
    
    return 0;
}
//只能被题目识别 还有一个函数在裁判系统里！！！！！！！！！！！！
void StringCount( char s[] ){
    int i;
    int letter = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    for (i = 0; s[i] != '\0'; i ++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            letter ++;
        }
        else if (s[i] >= '0' && s[i] <= '9'){
            digit ++;
        }
        else if (s[i] == ' '||s[i] == '\n'){
            blank ++;
        }
        else{
            other ++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
}
