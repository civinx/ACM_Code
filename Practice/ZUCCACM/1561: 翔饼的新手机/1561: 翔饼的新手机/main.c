//
//  main.c
//  1561: 翔饼的新手机
//
//  Created by czf on 15/10/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[101];
    int i;
    
    i = 0;
    while ((a[i] = getchar()) != '#') {
        i ++;
    }
    a[i] = '\0';
    
    for (i = 0; a[i] != '\0'; i ++) {
        if (a[i] >= 'a' && a[i] <= 'c') {
            printf("2");
        }
        else if (a[i] >= 'd' && a[i] <= 'f') {
            printf("3");
        }
        else if (a[i] >= 'g' && a[i] <= 'i') {
            printf("4");
        }
        else if (a[i] >= 'j' && a[i] <= 'l') {
            printf("5");
        }
        else if (a[i] >= 'm' && a[i] <= 'o') {
            printf("6");
        }
        else if (a[i] >= 'p' && a[i] <= 's') {
            printf("7");
        }
        else if (a[i] >= 't' && a[i] <= 'v') {
            printf("8");
        }
        else if (a[i] >= 'w' && a[i] <= 'z') {
            printf("9");
        }
        else if (a[i] == ' '){
            printf("0");
        }
      
    }
    return 0;
}
