//
//  main.c
//  实验8-1-9 输出学生成绩
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double *a;
    double sum;
    double max;
    double min;
    int i;
    
    scanf("%d",&n);
    
    if ((a = (double *) calloc(n, sizeof(double))) == NULL) {
        exit(1);
    }
    
    for (i = 0; i < n; i ++) {
        scanf("%lf",&*(a + i));
    }
              
    sum = 0;
    max = *a;
    min = *a;
    
    for (i = 0; i < n; i ++) {
        sum += *(a + i);
        if (*(a + i) > max) {
            max = *(a + i);
        }
        if (*(a + i) < min) {
            min = *(a + i);
        }
    }
    
    printf("average = %.2lf\nmax = %.2lf\nmin = %.2f\n",sum / n,max,min);
    
    free(a);
    
    return 0;
}
