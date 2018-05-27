//
//  main.c
//  实验11-2-6 奇数值结点链表
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
struct ListNode *getodd( struct ListNode **L );
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
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);
    
    return 0;
}

struct ListNode *readlist(){
    struct ListNode *p,*head,*last;
    head = last = NULL;
    int n;
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

struct ListNode *getodd( struct ListNode **L ){  //读入原链表的地址的地址
    struct ListNode *head,*last;
    struct ListNode *head1;
    struct ListNode *pt1,*pt2;
    head = last = NULL;            //奇数链表的头尾
    
    head1 = *L;                   //原链表的地址
    
    while (head1 != NULL && head1 -> data % 2 != 0) { //判断首位是否为奇数
        pt1 = head1;
        head1 = head1 -> next;  //若是 向后移位
        if (head == NULL) {     //若奇数链表为空 head为pt1
            head = pt1;
        }
        else{
            last = last -> next; //如果这动作连续两次以上 last接到head尾巴上
        }
        last = pt1;
//        last -> next = NULL;
    }
    if (head1 == NULL) { //如果原链表到头了 返回新偶数（剩余）为NULL
        (*L) = NULL;
    }
    else{
        pt1 = head1;
        pt2 = pt1 -> next;
        while (pt2 != NULL) { //从head后面一位开始遍历
            if (pt2 -> data % 2 != 0) {//如果符合
                if (head == NULL) {
                    head = pt2;
                }else{
                    last -> next = pt2;
                }
                last = pt2; //加到奇数链表中
                pt1 -> next = pt2 -> next; //先接后断
            }
            else{
                pt1 = pt2; //如果不符合 即pt2是偶数 pt1向后移位
            }
            pt2 = pt1 -> next; //不管怎样 pt2到pt1的后面一位
        }
        if (last != NULL) {
            last -> next = NULL;
        }
    }
    
    *L = head1;//修改原链表地址
    
    return head;
}
