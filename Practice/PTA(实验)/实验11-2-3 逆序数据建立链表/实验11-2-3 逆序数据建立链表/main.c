//
//  main.c
//  实验11-2-3 逆序数据建立链表
//
//  Created by czf on 15/10/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
    struct ListNode *p, *head = NULL;
    
    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");
    
    return 0;
}

struct ListNode *createlist(){
    struct ListNode *head,*last,*p;
    int num;
    head = last = NULL;
    scanf("%d",&num);
    while (num != -1) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p -> data = num;
        p -> next = head;
        head = p;
        scanf("%d",&num);
    }
    return head;
}
