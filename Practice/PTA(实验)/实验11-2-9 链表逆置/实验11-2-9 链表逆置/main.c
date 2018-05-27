//
//  main.c
//  实验11-2-9 链表逆置
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
struct ListNode *reverse( struct ListNode *head );
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
    struct ListNode  *head;
    
    head = createlist();
    head = reverse(head);
    printlist(head);
				
    return 0;
}

struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *p,*temp;
    p = NULL;
    if (head == NULL) {
        return  NULL;
    }
    while (head != NULL) {
        if (p == NULL) {
            p = head;
            head = head -> next;
            p -> next = NULL;
        }
        else{
            temp = head -> next;
            head -> next = p;
            p = head;
            head = temp;
        }
    }
    return p;
}

struct ListNode *createlist(){
    struct ListNode *head,*last,*p;
    int n;
    head = last = NULL;
    scanf("%d",&n);
    while (n != -1) {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p -> data = n;
        p -> next = NULL;
        if (head == NULL) {
            head = p;
        }
        else{
            last -> next = p;
        }
        last = p;
        scanf("%d",&n);
    }
    return head;
}