//
//  main.c
//  4-5 链式表操作集
//
//  Created by czf on 16/1/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;
    
    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

Position Find( List L, ElementType X ){
    for(int i = 1; L; L = L->Next, i++)
        if (L->Data == X) return L;
    return ERROR;
}

List Insert( List L, ElementType X, Position P ){
    Position Ans = NULL, head = L;
    for(; L || L == P; L = L->Next){
        if (L == P){
            P = (Position)malloc(sizeof(struct LNode));
            P->Data = X;
            if (Ans){
                Ans->Next = P;
                P->Next = L;
                return head;
            }
            else{
                P->Next = L;
                return P;
            }
        }
        Ans = L;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}

List Delete( List L, Position P ){
    List head = L;
    Position Ans = NULL;
    for(; L; L = L->Next){
        if (L == P){
            if (Ans){
                Ans->Next = L->Next;
                return head;
            }
            else{
                L = L->Next;
                return L;
            }
        }
        Ans = L;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}