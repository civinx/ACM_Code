//
//  main.c
//  4-7 在一个数组中实现两个堆栈
//
//  Created by czf on 16/1/21.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;
    
    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
            case push:
                scanf("%d %d", &Tag, &X);
                if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
                break;
            case pop:
                scanf("%d", &Tag);
                X = Pop(S, Tag);
                if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
                break;
            case end:
                PrintStack(S, 1);
                PrintStack(S, 2);
                done = 1;
                break;
        }
    }
    return 0;
}

Stack CreateStack( int MaxSize ){
    Stack ret;
    ret = (Stack)malloc(sizeof(struct SNode));
    ret->MaxSize = MaxSize;
    ret->Top1 = -1; ret->Top2 = MaxSize;
    ret->Data = (int*)calloc(MaxSize,sizeof(int));
    return ret;
}

bool Push( Stack S, ElementType X, int Tag ){
    if (S->Top2-S->Top1 > 1){
        if (Tag == 1)
            S->Data[++S->Top1] = X;
        else
            S->Data[--S->Top2] = X;
        return true;
    }
    printf("Stack Full\n");
    return false;
}

ElementType Pop( Stack S, int Tag ){
    if ((Tag==1 && S->Top1==-1) || (Tag==2 && S->Top2==S->MaxSize)){
        printf("Stack %d Empty\n",Tag);
        return ERROR;
    }
    return Tag==1 ? S->Data[S->Top1--] : S->Data[S->Top2++];
}

Operation GetOp(){
    char s[10];
    scanf("%s",s);
    switch (s[1]) {
        case 'u':
            return push;
        case 'o':
            return pop;
        default:
            return end;
    }
}

void PrintStack( Stack S, int Tag ){
    printf("Pop from Stack %d",Tag);
    if (Tag == 1)
        for (int i = 0; i <= S->Top1; i++)
            printf(" %d",S->Data[i]);
    else
        for (int i = S->Top2; i < S->MaxSize; i ++)
                printf(" %d",S->Data[i]);
    putchar('\n');
}

