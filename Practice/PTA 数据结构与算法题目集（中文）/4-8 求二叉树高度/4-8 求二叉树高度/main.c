//
//  main.c
//  4-8 求二叉树高度
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
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
int GetHeight( BinTree BT ){
    if (BT == NULL) {
        return 0;
    }
    int left = GetHeight(BT->Left);
    int right = GetHeight(BT->Right);
    return 1 + (left > right ? left : right);
}