//
//  main.c
//  4-6 带头结点的链式表操作集
//
//  Created by czf on 16/1/21.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {false, true} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;
    
    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if ( flag==false ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( flag==false )
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if ( flag==false ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if ( flag==true ) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if ( flag==true ) printf("Wrong Answer\n");
    for ( P=L->Next; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

List MakeEmpty(){
    List ret;
    ret = (List)malloc(sizeof(struct LNode));
    ret->Next = NULL;
    return ret;
}

Position Find( List L, ElementType X ){
    for(; L; L = L->Next)
        if (L->Data == X)
            return L;
    return ERROR;
}

bool Insert( List L, ElementType X, Position P ){
    Position Ans = L;
    for(L = L->Next; L || L == P; L = L->Next){
        if(P == L){
            P = (Position)malloc(sizeof(struct LNode));
            P->Data = X;
            P->Next = Ans->Next;
            Ans->Next = P;
            return true;
        }
        Ans = L;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete(List L, Position P ) {
    Position Ans = L;
    for(L = L->Next; L; L = L->Next){
        if(L == P){
            Ans->Next = P->Next;
            free(P);
            return true;
        }
        Ans = L;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}



