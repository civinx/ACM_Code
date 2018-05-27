//
//  main.c
//  实验11-2-5 链表拼接
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

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2);
void printlist( struct ListNode *head )
{
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode  *list1, *list2;
    
    list1 = createlist();
    list2 = createlist();
    list1 = mergelists(list1, list2);
    printlist(list1);
				
    return 0;
}

struct ListNode *mergelists(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *p1,*p2;
    int temp;
    int flag = 1;
    if (list1 == NULL && list2 == NULL) {
        flag = 0;
        return NULL;
    }
    for (p1 = list1; p1 -> next != NULL; p1 = p1 -> next) {
    }
    p1 -> next = list2;
    
    for (p1 = list1; p1 -> next != NULL; p1 = p1 -> next) {
        for (p2 = list1; p2 -> next != NULL; p2 = p2 -> next) {
            if (p2 -> data > p2 -> next -> data) {
                temp = p2 -> data;
                p2 -> data = p2 -> next -> data;
                p2 -> next -> data = temp;
            }
        }
    }
    return list1;
}
