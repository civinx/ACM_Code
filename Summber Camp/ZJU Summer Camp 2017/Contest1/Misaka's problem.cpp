#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long LL;
const LL INF = 1e16;
const int maxn = 2000 + 100;

//vector<string> res;

void solve(string & s) {
    for (int i = 0; i < s.size(); i ++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

void solve1(string & s) {
    s[0] = s[0] - 'a' + 'A';
}

char s[10000 + 100];

int main() {
    //    freopen("A.in", "r", stdin);
    int T; scanf("%d",&T);
    cin.get();
    //    string s;  getline(cin, s);
    while (T--) {
        //        getline(cin, s);
        gets(s);
        int len = strlen(s);
        int flag = 0;
        string temp = "";
        for (int i = 0; i < len; i ++) {
            if (s[i] == ' ' && (i == 0 || s[i-1] != ' ')) {
                solve(temp);
                solve1(temp);
                if (flag == 0)
                    cout << temp << " ";
                else {
                    cout << temp[0];
                    if (temp.size() > 1) {
                        cout << ".";
                    }
                    cout << " ";
                }
                
                flag ++;
                temp = "";
            } else {
                if (s[i] != ' ')
                    temp += s[i];
            }
            
        }
        solve(temp);
        solve1(temp);
        cout << temp << '\n';
    }
    return 0;
}
