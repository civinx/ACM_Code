#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1000+5
struct node {
    int a, b, c;
};
node sta[maxn], en[maxn], sum;
int main() {
    int t, cnt = 0;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p1,p2,p3;
        cin >> p1 >> p2 >> p3;
        sum.a = p1;
        sum.b = p2;
        sum.c = p3;
        for(int i = 0; i < n; i++) {
            cin >> sta[i].a >> sta[i].b >> sta[i].c >> en[i].a >> en[i].b >> en[i].c;
            sum.a += sta[i].a;
            sum.b += sta[i].b;
            sum.c += sta[i].c;
        }
        int flag = 1;
        for(int i = 0; i < n; i++) {
            if(sum.a-sta[i].a<en[i].a-sta[i].a || sum.b-sta[i].b<en[i].b-sta[i].b || sum.c-sta[i].c<en[i].c-sta[i].c) {
                flag = 0;
                break;
            }	
        }
        printf("Case #%d: ", ++cnt);	
        if(flag)	printf("Yes\n");
        else	printf("No\n");
    }
    return 0;
} 
