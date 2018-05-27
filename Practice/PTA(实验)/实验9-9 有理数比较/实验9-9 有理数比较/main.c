//
//  main.c
//  实验9-9 有理数比较
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
struct fenshi{
    double fenzi;
    double fenmu;
    double jieguo;
};
int main() {
    struct fenshi a,b;
    scanf("%lf/%lf %lf/%lf",&a.fenzi,&a.fenmu,&b.fenzi,&b.fenmu);
    a.jieguo = a.fenzi / a.fenmu;
    b.jieguo = b.fenzi / b.fenmu;
    
    if (a.jieguo > b.jieguo) {
        printf("%.lf/%.lf > %.lf/%.lf",a.fenzi,a.fenmu,b.fenzi,b.fenmu);
    }
    if (a.jieguo < b.jieguo) {
        printf("%.lf/%.lf < %.lf/%.lf",a.fenzi,a.fenmu,b.fenzi,b.fenmu);
    }
    if (a.jieguo == b.jieguo) {
        printf("%.lf/%.lf = %.lf/%.lf",a.fenzi,a.fenmu,b.fenzi,b.fenmu);
    }
    return 0;
}
