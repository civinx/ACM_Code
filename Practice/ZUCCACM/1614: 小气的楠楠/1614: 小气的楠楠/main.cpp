
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, m; scanf("%d%d",&n,&m);
        int a[maxn], b[maxn];
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i ++) scanf("%d",&b[i]);
        sort(a,a+n); sort(b,b+n);
        int res = 0;
        int l = 0, r = n-1;
        while(m--){
            if (a[r]*b[r] >= 0 && a[l]*b[l] >= 0){
                if (a[r]*b[r] > a[l]*b[l]) {res += a[r]*b[r]; r --;}
                else {res += a[l]*b[l]; l ++;}
            }
            else if (a[r]*b[r]>=0) {res += a[r]*b[r]; r --;}
            else if (a[l]*b[l]>=0) {res += a[l]*b[l]; l ++;}
            else{
                int k = m+1, x[maxn], y[maxn];
                if (a[l] > 0)
                    for(int i = 0; i < k; i ++){
                        x[i] = a[l++];
                        y[i] = b[r--];
                    }
                else
                    for(int i = 0; i < k; i ++){
                        x[i] = a[r--];
                        y[i] = b[l++];
                    }
                sort(x,x+k); sort(y,y+k);
                for(int i = 0; i < k; i ++){
                    res += x[i]*y[i];
                }
                break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}