//
//  main.c
//  实验11-2-8 单链表结点删除
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

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
    struct ListNode *p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);
    
    return 0;
}

struct ListNode *readlist(){
    struct ListNode *p,*head,*last;
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

struct ListNode *deletem( struct ListNode *L, int m ){
    struct ListNode *pt1,*pt2;
    while (L != NULL && L -> data == m) {
        pt1 = L;
        L = L -> next;
        free(pt1);
    }
    if (L == NULL) {
        return NULL;
    }
    pt1 = L;
    pt2 = pt1 -> next;
    
    while (pt2 != NULL) {
        if (pt2 -> data == m) {
            pt1 -> next = pt2 -> next;
            free(pt2);
        }
        else{
            pt1 = pt2;
        }
        pt2 = pt1 -> next;
    }
    return L;
}