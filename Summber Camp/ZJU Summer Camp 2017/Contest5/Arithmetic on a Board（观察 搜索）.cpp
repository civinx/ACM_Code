#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

const int maxn = 100000 + 100;

int a[maxn];

int res, n;


void dfs(vector<int> v) {
    if (v.size() == 1) {
        res = min(res, v[0]);
        return;
    }
    vector<int> temp = v;
    for (int i = 0; i < v.size(); i ++) {
        for (int j = i+1; j < v.size(); j ++) {
            int x = v[i];
            int y = v[j];
            
            swap(temp.back(), temp[j]); temp.pop_back();
            swap(temp.back(), temp[i]); temp.pop_back();
            
            temp.push_back(x + y);
            dfs(temp);
            temp.pop_back();
            
            temp.push_back(x * y);
            dfs(temp);
            temp.pop_back();
            
            temp.push_back(abs(x - y));
            dfs(temp);
            temp.pop_back();
            temp = v;
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
        }
        if (n > 5) {
            printf("0\n");
            continue;
        }
        
        vector<int> v;
        for (int i = 1; i <= n; i ++) {
            v.push_back(a[i]);
        }
        res = maxn;
        dfs(v);
        printf("%d\n",res);
    }
    
    return 0;
}