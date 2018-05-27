//
//  main.cpp
//  Problem : Subsequence
//
//  Created by czf on 16/5/12.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 100000 + 100;

int a[maxn], Max[maxn], Min[maxn];

int main() {
    int n, m, k;
    while (~scanf("%d%d%d",&n,&m,&k)) {
        for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
        int Max_head = 0, Max_rear = -1;
        int Min_head = 0, Min_rear = -1;
        int res = 0;
        for (int l = 0, r = 0; r < n; r ++) {
            //找到Max中大于等于a[r]的第一个值，然后将a[r]放在后面，如果全比a[r]小，那么rear将等于-1
            //++rear正好等于0（注意 如果Max[Max_rear] <= a[r]的话会把相同的值覆盖掉）
            while (Max_head <= Max_rear && Max[Max_rear] < a[r]) Max_rear --;
            Max[++Max_rear] = a[r];
            
            //找到Min中小于等于a[r]的第一个值，然后将a[r]放在后面，如果全比a[r]大，那么rear将等于-1
            //++rear正好等于0
            while (Min_head <= Min_rear && Min[Min_rear] > a[r]) Min_rear --;
            Min[++Min_rear] = a[r];
            
            //窗口左边界右移，并同时更新队列
            while (Max[Max_head] - Min[Min_head] > k) {
                if (a[l] == Max[Max_head]) Max_head ++;
                if (a[l] == Min[Min_head]) Min_head ++;
                l ++;
            }
            
            if (l <= r && Max[Max_head] - Min[Min_head] >= m) {
                if (r - l + 1 > res) res = r - l + 1;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
