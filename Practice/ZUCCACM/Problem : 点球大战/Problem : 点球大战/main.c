//
//  main.c
//  Problem : 点球大战
//
//  Created by czf on 15/10/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAXN 105

int Isgoal (char a[],int x);

int main() {
    char a[MAXN];
    char team_1[MAXN];
    char team_2[MAXN];
    int cnt_team1 = 0;
    int cnt_team2 = 0;
    int n;
    while (scanf("%d",&n) == 1 && n) {
        cnt_team1 = 0;
        cnt_team2 = 0;
        
        int num = (n+1)/2;

        getchar();
        for (int i = 1; i <= n; i ++) { //计数
            
            for (int i = 0; i < MAXN; i ++) a[i] = '\0'; //保险初始数组
            
            gets(a);
            int x = strlen(a);
            if (i % 2 == 1) {
                if (Isgoal(a, x)) {team_1[(i+1)/2] = 'O'; cnt_team1++;}
                else team_1[(i+1)/2] = 'X';
            }
            else {
                if (Isgoal(a, x)) {team_2[i/2] = 'O'; cnt_team2++;}
                else team_2[i/2] = 'X';
            }

        }
        
        for (int i = 1; i <= num; i ++) printf("%d ",i);
        printf("Score\n");
        
        for (int i = 1; i <= num; i ++) {
            printf("%c ",team_1[i]);
        }
        printf("%d\n",cnt_team1);
        
        for (int i = 1; i <= num; i ++) {
            if (team_2[i] != 'O' && team_2[i] != 'X') printf("- ");
            else printf("%c ",team_2[i]);
        }
        printf("%d\n",cnt_team2);
    }
    return 0;
}

int Isgoal (char a[], int x){
    int ret = 1;
    if (a[x-7] == 'n' && a[x-6] == 'o' && a[x-8] == ' ' && a[x-5] == ' ') ret = 0;
    return ret;
}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[110][105];
//    int n,i,k,score[2],cont,len[110];
//    char c[108];
//    
//    while(scanf("%d",&n)!=EOF && n)
//    {
//        getchar();
//        score[0] = score[1] = 0;
//        cont = 0;
//        if(n%2 == 0)
//            k = n/2;
//        else
//            k = (n+1)/2;
//        for(i = 1; i<=n; i++)
//        {
//            gets(str[i]);
//            len[i] = strlen(str[i]);
//        }
//        for(i = 1; i<=k; i++)//打出计分板第一行
//        {
//            if(i == 1)
//                printf("%d",i);
//            else
//                printf(" %d",i);
//        }
//        printf(" Score\n");
//        for(i = 1; i<=n; i++)
//        {
//            if(str[i][len[i]-7] == 'n' && str[i][len[i]-6] == 'o' && str[i][len[i]-8] == ' ' && str[i][len[i]-5] == ' ')//关键在于判断no而且no的位置很重要，而且no前后要有空格
//            {
//                c[i] = 'X';
//            }
//            else
//            {
//                c[i] = 'O';
//                if(i%2 == 0)//分别记录两队得分状况
//                    score[1]++;
//                else
//                    score[0]++;
//            }
//        }
//        for(i = 1; i<=n; i+=2)//打出1队的得分情况
//        {
//            putchar(c[i]);
//            putchar(' ');
//        }
//        printf("%d\n",score[0]);
//        for(i = 2; i<=n; i+=2)//打出2队的得分情况
//        {
//            putchar(c[i]);
//            putchar(' ');
//            cont++;
//        }
//        if(cont!=k)
//            printf("- ");
//        printf("%d\n",score[1]);
//    }
//    
//    return 0;
//}

