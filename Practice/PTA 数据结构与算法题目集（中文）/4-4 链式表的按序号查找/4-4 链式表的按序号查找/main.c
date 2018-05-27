//
//  main.c
//  4-4 链式表的按序号查找
//
//  Created by czf on 16/1/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

ElementType FindKth( List L, int K ){
    for(int i = 1; L; L = L->Next)
        if (i++ == K)
            return L->Data;
    return ERROR;
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
        scanf("%d",&x);
    }
    if (last)
        last -> Next = NULL;
    return head;
}