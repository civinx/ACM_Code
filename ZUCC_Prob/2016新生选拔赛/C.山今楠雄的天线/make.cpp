#include <bits/stdc++.h>
using namespace std;

int main() {
  	srand (time(NULL));
	int T = 100000-7; 
	cout << T+7 << endl;
	cout << 5 << " " << 2 << " " << 3 << endl;
	cout << 10 << " " << 3 << " " << 4 << endl;
	cout << 150 << " " << 3 << " " << 5 << endl;
	cout << 3000 << " " << 4 << " " << 8 << endl;
	cout << 2 << " " << 7 << " " << 8 << endl;
	cout << 1000000000 << " " << 345 << " " << 567 << endl;
    cout << 23452 << " " << 4 << " " << 6 << endl;
	while (T--) {
    	int a = rand() % 100000000;
    	int b = rand() % 10000;
    	int c = rand() % 10000;
    	if(!a || !b || !c) 
		{
    		T++;
    		continue;
    	}
		cout << a << " " << b << " " << c << endl;
  	}
  	return 0;
}
