#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000000 + 100;

int a[maxn];

int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i ++) {
			int x; scanf("%d",&x);
			a[x] ++;
		}
		int res = 0;
		for (int i = 1; i <= n; i ++) {
			res += a[i] / 2;
			a[i] &= 1;
			if (i+2 <= n && a[i] && a[i+1]%2 && a[i+2]) {
				res ++;
				a[i] = 0; a[i+1] --; a[i+2] --;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}