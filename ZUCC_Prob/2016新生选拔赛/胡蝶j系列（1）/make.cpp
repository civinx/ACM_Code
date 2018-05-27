#include <bits/stdc++.h>
using namespace std;
int main()
{

  srand (time(NULL));
  int T = 1000;
  cout << T << endl;
  while (T--) {
    // rand() 能产生 0 .. 32767 的随机数
    // Ref: http://www.cplusplus.com/reference/cstdlib/rand
    // 如果需要更大的随机数，请使用 c++11 的 random 库
    // Ref: http://www.cplusplus.com/reference/random
    // 对 100 取模后能保证数字在范围 0 .. 99 中
    long long t1 = rand();
    long long t2 = rand();
    long long a = t1*t2 % 100000;
    long long b = t1*t2 %a;
      if (a == 0 || b == 0) {
          T ++;
          continue;
      }
    cout << a << " " << b << endl;
  }
  return 0;
}

