//
//  main.c
//  5-2 一元多项式的乘法与加法运算
//
//  Created by czf on 16/1/17.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int coef;
    int expon;
    struct _node *next;
} Node;

int Compare(int e1, int e2);
Node* CreatList(int n);
Node* NodeAdd(Node *p1, Node *p2);
Node* NodeMul(Node *p1, Node *p2);
Node* NodeMul_ast(Node *p1, Node *p2);
void Attach(int c, int e, Node **last);
void NodePrint(Node *p);

int main(){
    int n;
    Node *p1, *p2, *p3, *p4;
    scanf("%d",&n); p1 = CreatList(n);
    scanf("%d",&n); p2 = CreatList(n);
    p3 = NodeMul(p1,p2);
    p4 = NodeAdd(p1,p2);
    NodePrint(p3);
    NodePrint(p4);
    return 0;
}

int Compare(int e1, int e2){
    if (e1 > e2) return 1;
    if (e1 < e2) return -1;
    return 0;
}

Node* CreatList(int n){
    Node *head, *last, *temp;
    int c, e;
    head = last = NULL;
    while(n--){
        scanf("%d%d",&c,&e);
        temp = (Node*)malloc(sizeof(Node));
        temp->coef = c;
        temp->expon = e;
        if(head == NULL){
            head = temp;
        }
        else{
            last->next = temp;
        }
        last = temp;
    }
    return head;
}

Node* NodeAdd(Node *p1, Node *p2){
    Node *head, *last, *temp;
    int sum;
    last = (Node*)malloc(sizeof(Node));
    head = last;
    while(p1 && p2){
        switch(Compare(p1->expon,p2->expon)){
            case 1:
                Attach(p1->coef,p1->expon,&last);
                p1 = p1->next;
                break;
            case -1:
                Attach(p2->coef,p2->expon,&last);
                p2 = p2->next;
                break;
            case 0:
                sum = p1->coef+p2->coef;
                if (sum) Attach(sum,p1->expon,&last);
                p1 = p1->next; p2 = p2->next;
                break;
        }
    }
    for(; p1; p1 = p1->next) Attach(p1->coef,p1->expon,&last);
    for(; p2; p2 = p2->next) Attach(p2->coef,p2->expon,&last);
    last->next = NULL;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* NodeMul(Node *p1, Node *p2){
    if(p1 == NULL || p2 == NULL || p1->coef == 0 || p2->coef == 0) return NULL;
    Node *head = NULL, *temp;
    while(p1){
        temp = NodeMul_ast(p1,p2);
        head = NodeAdd(head,temp);
        p1 = p1->next;
    }
    return head;
}

Node* NodeMul_ast(Node *p1, Node *p2){
    if(p1 == NULL || p2 == NULL || p1->coef == 0 || p2->coef == 0) return NULL;
    Node *head, *last , *temp;
    int c, e;
    head = last = temp = (Node*)malloc(sizeof(Node));
    while(p2){
        c = p1->coef * p2->coef;
        e = p1->expon + p2->expon;
        Attach(c,e,&last);
        p2 = p2->next;
    }
    last->next = NULL;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void Attach(int c, int e, Node **last){
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->coef = c;
    temp->expon = e;
    (*last)->next = temp;
    *last = temp;
}

void NodePrint(Node *p){
    if (p == NULL)
        printf("0 0\n");
    while(p){
        printf("%d %d",p->coef,p->expon);
        if (p->next) printf(" ");
        else printf("\n");
        p = p->next;
    }
}
