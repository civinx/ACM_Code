#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int len; scanf("%d",&len);
        string s;
        if (len) {
            cin >> s;
        }

        int sum = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == 'l') {
                sum ++;
            } else if (s[i] == 'r') {
                sum ++;
            }
        }
        sum ++;
        int g = sum % 3 + 1;
        for (int i = 1; i <= 3; i ++) {
            if (i == g) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
