#include <bits/stdc++.h>
using namespace std;
int main()
{
  // ����� rand() Ҫ��ʼ���������
  srand (time(NULL));

  // Ϊ���չ������������е�һ��Ϊ T����ʾ�� T ��������
  int T = 80;
  cout << T << endl;
  T--;
  while (T--) {
    // rand() �ܲ��� 0 .. 32767 �������
    // Ref: http://www.cplusplus.com/reference/cstdlib/rand
    // �����Ҫ��������������ʹ�� c++11 �� random ��
    // Ref: http://www.cplusplus.com/reference/random
    // �� 100 ȡģ���ܱ�֤�����ڷ�Χ 0 .. 99 ��
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

