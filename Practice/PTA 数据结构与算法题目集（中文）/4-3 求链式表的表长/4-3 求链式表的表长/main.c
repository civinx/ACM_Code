//
//  main.c
//  4-3 求链式表的表长
//
//  Created by czf on 16/1/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

int Length( List L ){
    if (L == NULL)
        return 0;
    int cnt = 1;
    while(L->Next){
        cnt ++;
        L = L->Next;
    }
    return cnt;
}

List Read(){
    int x;
    List head, last, temp;
    head = last = NULL;
    scanf("%d",&x);
    while(x != -1){
        temp = (List)malloc(sizeof(struct LNode));
        temp->Data = x;
        if (head == NULL) head = temp;
        else last->Next = temp;
        last = temp;
        last -> Next = NULL;
        scanf("%d",&x);
    }
    return head;
}
