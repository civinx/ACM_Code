//
//  main.c
//  实验11-2-1 建立学生信息链表
//
//  Created by czf on 15/10/4.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node {
    int    num;
    char   name[20];
    int    score;
    struct stud_node *next;
};
struct stud_node *head, *tail;
void input();
int main()
{
    struct stud_node *p;
				
    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);
    
    return 0;
}
void input(){
    struct stud_node *p;
    int num;
    int score;
    char name[20];
    scanf("%d%s%d",&num,name,&score);
    while (num != 0) {
        p = (struct stud_node *) malloc(sizeof(struct stud_node));
        p -> num = num;
        strcpy(p -> name, name);
        p -> score = score;
        p -> next = NULL;
        if (head == NULL) {
            head = p;
        }
        else{
            tail -> next = p;
        }
        tail = p;
        scanf("%d%s%d",&num,name,&score);
    }
}