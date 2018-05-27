//
//  main.c
//  实验11-2-7 统计专业人数
//
//  Created by czf on 15/10/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char code[8];
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
int countcs( struct ListNode *head );

int main()
{
    struct ListNode  *head;
    
    head = createlist();
    printf("%d\n", countcs(head));
				
    return 0;
}

int countcs( struct ListNode *head ){
    int cnt = 0;
    struct ListNode *p;
    for (p = head; p != NULL; p = p -> next) {
        if (p -> code[1] == '0' && p -> code[2] == '2') {
            cnt ++;
        }
    }
    return cnt;
}
