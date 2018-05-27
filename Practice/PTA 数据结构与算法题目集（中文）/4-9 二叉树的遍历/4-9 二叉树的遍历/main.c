//
//  main.c
//  4-9 二叉树的遍历
//
//  Created by czf on 16/2/13.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}

void InorderTraversal( BinTree BT ){
    if (BT == NULL) return;
    InorderTraversal(BT->Left);
    printf(" %c",BT->Data);
    InorderTraversal(BT->Right);
}

void PreorderTraversal( BinTree BT ){
    if (BT == NULL) return;
    printf(" %c",BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal( BinTree BT ){
    if (BT == NULL) return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c",BT->Data);
}

int GetHeight(BinTree BT){
    if (BT == NULL) return 0;
    int left = GetHeight(BT->Left);
    int right = GetHeight(BT->Right);
    return 1 + (left > right ? left : right);
}

void PrintNode(BinTree BT, int h){
    if (BT == NULL || h < 1) return;
    if (h == 1) {printf(" %c",BT->Data); return;}
    PrintNode(BT->Left, h-1);
    PrintNode(BT->Right, h-1);
}

void LevelorderTraversal( BinTree BT ){
    if (BT == NULL) return;
    int h = GetHeight(BT);
    for (int i = 1; i <= h; i ++) {
        PrintNode(BT,i);
    }
}