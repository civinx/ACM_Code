#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
#define AS(x, L, R) assert((L) <= x && x <= (R))
using namespace std;
typedef long long LL;


const int small_cases = 50;
const int small_n = 20;
const int small_k = 20;

const int large_cases = 50;
const int large_n = 1e4;
const int large_k = 1e4;

int rd()
{
    //return (rand() + (rand() << 15)) % (1000000000-1) + 1;
    return rand() % (1000000000-1) + 1;
}


int main()
{
    //printf("%d\n", RAND_MAX);
    // freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int T = small_cases + large_cases;
//    printf("%d\n", T);
    cout << T << endl;
    for(int Case = 1; Case <= small_cases; ++Case)
    {
        int n = rd() % small_n + 1;
        int k = rd() % small_k + 1;
        if (k > n) swap(n, k);
        cout << n << " " << k << endl;
    }
    for(int Case = 1; Case <= large_cases; ++Case)
    {
        int n = rd() % large_n + 1;
        int k = rd() % large_k + 1;
        if (k > n) swap(n, k);
        cout << n << " " << k << endl;
    }
    return 0;
}
