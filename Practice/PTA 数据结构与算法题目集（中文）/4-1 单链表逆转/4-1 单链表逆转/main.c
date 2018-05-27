//
//  main.c
//  4-1 单链表逆转
//
//  Created by czf on 16/1/17.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse( List L ){
    List p = NULL, q = NULL;
    while(L){
        q = L->Next;
        L->Next = p;
        p = L;
        L = q;
    }
    return p;
}

List Read(){
    List head, last, p;
    head = last = NULL;
    int n; scanf("%d",&n);
    while(n--){
        int x; scanf("%d",&x);
        p = (List)malloc(sizeof(struct Node));
        p->Data = x;
        if(head == NULL){
            head = p;
        }
        else{
            last->Next = p;
        }
        last = p;
    }
    last->Next = NULL;
    return head;
}

void Print( List L ){
    if( NULL == L  ){
        return ;
    }
    PtrToNode last = L;
    while(  NULL != last  ){
        printf( "%d ",last->Data );
        last = last->Next;
    }
    putchar( '\n' );
}