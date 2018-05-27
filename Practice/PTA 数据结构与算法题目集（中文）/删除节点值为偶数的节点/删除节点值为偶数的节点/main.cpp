//
//  main.cpp
//  删除节点值为偶数的节点
//
//  Created by czf on 16/3/10.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node{
    int x;
    Node *next;
}*pNode;

int main(){
    int n; cin >> n;
    pNode head = NULL, tail = NULL, temp;
    for(int i = 0; i < n; i ++){
        int x; cin >> x;
        temp = new Node;
        temp->x = x; temp->next = NULL;
        if (!head){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    pNode ans = NULL;
    for(temp = head; temp;){
        if (temp->x % 2 == 0){
            if (ans) { //非头节点
                ans->next = temp->next;//前节点与后节点连接
                temp = temp->next;//temp前进一个
            }
            else { //头结点为偶数
                head = head->next; //头结点前进一个
                temp = head; //temp从新的头结点开始
                ans = NULL;//ans归零
                continue;
            }
        }
        else{
            pNode temp1 = temp;
            temp = temp->next;
            ans = temp1;
        }
    }
    for (temp = head; temp; temp = temp->next) {
        cout << temp->x << " ";
    }
    return 0;
}
