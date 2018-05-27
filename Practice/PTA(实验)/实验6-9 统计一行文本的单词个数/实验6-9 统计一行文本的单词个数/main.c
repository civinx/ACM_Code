//
//  main.c
//  实验6-9 统计一行文本的单词个数
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int cnt = 0;
    char x;
    char y;
    
    y = ' ';
    while ((x = getchar())!='\n') {
        if (x != ' ' && y == ' ') {
            cnt ++;
        }
        y = x;
    }
    
    printf("%d",cnt);
    
    return 0;
}
