#include <bits/stdc++.h>
using namespace std;
int main()
{

  srand (time(NULL));
  int T = 1000;
  cout << T << endl;
  while (T--) {
    // rand() �ܲ��� 0 .. 32767 �������
    // Ref: http://www.cplusplus.com/reference/cstdlib/rand
    // �����Ҫ��������������ʹ�� c++11 �� random ��
    // Ref: http://www.cplusplus.com/reference/random
    // �� 100 ȡģ���ܱ�֤�����ڷ�Χ 0 .. 99 ��
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

