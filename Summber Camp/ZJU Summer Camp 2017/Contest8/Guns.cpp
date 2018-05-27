#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        double res = 0;
        for (int i = 1; i <= n-1; i ++) {
            res += (1.0 / (i + 1.0));
        }
        printf("%.4f\n",res);
    }
    return 0;
}