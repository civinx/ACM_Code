//
//  main.c
//  5-4 是否同一棵二叉搜索树
//
//  Created by czf on 16/2/14.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
typedef struct TNode *Position;
typedef Position Bintree;
typedef int ElementType;
struct TNode{
    int Data;
    Bintree Left;
    Bintree Right;
};

Bintree Insert(Bintree BST, ElementType X){
    if (!BST){
        BST = (Bintree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }else{
        if (X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else if(X > BST->Data)
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}

bool Judge(Bintree SampleTree, Bintree TextTree){
    if (SampleTree == NULL && TextTree == NULL){ //都为空
        return true;
    }
    if (SampleTree == NULL || TextTree == NULL){ //一空一非空
        return false;
    }
    if (SampleTree->Data != TextTree->Data){
        return false;
    }
    return Judge(SampleTree->Left, TextTree->Left) && Judge(SampleTree->Right, TextTree->Right);
}

void TreeFree(Bintree *BST){
    if (!*BST) return;
    TreeFree(&(*BST)->Left);
    TreeFree(&(*BST)->Right);
    free(*BST);
    *BST = NULL;
}

int main(){
    int N, L;
    while (scanf("%d",&N) && N) {
        scanf("%d",&L);
        Bintree SampleTree = NULL, TextTree = NULL;
        int x;
        for (int i = 0; i < N; i ++){
            scanf("%d",&x);
            SampleTree = Insert(SampleTree, x);
        }
        for (int i = 0; i < L; i ++) {
            for (int j = 0; j < N; j ++) {
                scanf("%d",&x);
                TextTree = Insert(TextTree, x);
            }
            if (Judge(SampleTree, TextTree)) printf("Yes\n");
            else printf("No\n");
            TreeFree(&TextTree);
        }
    }
    return 0;
}