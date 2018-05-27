#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
const int MAXN = 1000;
const int MAXM = 1000000000;
const int MAXK = 30;

int main() {
    // 如果用 rand() 要初始化随机种子
    srand (time(NULL));
    
    // 为了照顾新生，输入中第一行为 T，表示有 T 组样例。
    long long t1 ;
    long long t2 ;
    long long T = 850;
    cout << T << endl;
    while (T--) {
        // rand() 能产生 0 .. 32767 的随机数
        // Ref: http://www.cplusplus.com/reference/cstdlib/rand
        // 如果需要更大的随机数，请使用 c++11 的 random 库
        // Ref: http://www.cplusplus.com/reference/random
        // 对 100 取模后能保证数字在范围 0 .. 99 中
        if (T >= 300)
            t1 =  rand() % MAXN;
        else if (T >= 50) {
            int k = rand() % MAXK;
            t1 = (long long)pow(2, k);
        } else {
            t1 = rand() % MAXM;
        }
        if (!t1) t1 ++;
        cout << t1 << endl;
    }
    
    return 0;
}
