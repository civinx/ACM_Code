#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 如果用 rand() 要初始化随机种子
  srand (time(NULL));

  // 为了照顾新生，输入中第一行为 T，表示有 T 组样例。
  int T = 80;
  cout << T << endl;
  T--;
  while (T--) {
    // rand() 能产生 0 .. 32767 的随机数
    // Ref: http://www.cplusplus.com/reference/cstdlib/rand
    // 如果需要更大的随机数，请使用 c++11 的 random 库
    // Ref: http://www.cplusplus.com/reference/random
    // 对 100 取模后能保证数字在范围 0 .. 99 中
    long long t1 = rand();
    long long t2 = rand();
    long long a = (t1*t2) % 100000;
    t1 = rand();
    t2 = rand();
    long long b = (t1*t2) % 1000000;
    cout << a << " " << b << endl;
  }
  cout << 99999 << " " << 999999 << endl;
  return 0;
}

