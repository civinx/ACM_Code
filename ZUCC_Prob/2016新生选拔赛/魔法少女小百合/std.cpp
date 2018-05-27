#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[1050][2050];
int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(map, 0, sizeof(map));
        int n;
        cin >> n;
        n ++;
        for(int i = 1; i <= (1<<n)-1; i+=2) {
            if(i%4 == 3)
                for(int j = (1<<n)-1-i; j <= ((1<<n)-1); j+=4){
                    map[i][j] = '/';
                    map[i][j+1] = map[i][j+2] = '_';
                    map[i][j+3] =  '\\';
                    map[i-1][j+1] = '/';
                    map[i-1][j+2]  = '\\';
                }
            else
                for(int j = (1<<n)-1-i; j <= (1<<n)-1; j+=8) {
                    map[i][j] = '/';
                    map[i][j+1] = map[i][j+2] = '_';
                    map[i][j+3] =  '\\';
                    map[i-1][j+1] = '/';
                    map[i-1][j+2]  = '\\';
                }
        }
        for(int i = 2; i <= (1<<n)-1; i++)
            for(int j = (1<<n); j <= (1<<(n+1))-1; j++)
                if(!map[i][j])
                    if(map[i][(1<<(n+1))-1-j] == '\\')
                        map[i][j] = '/';
                    else if(map[i][(1<<(n+1))-1-j] == '/')
                        map[i][j] = '\\';
                    else if(map[i][(1<<(n+1))-1-j] == '_')	map[i][j] = '_';
        
        for(int i = 0; i <= (1<<n)-1; i++) {
            for(int j = 0; j <= (1<<(n+1))-1; j++)
                if(!map[i][j])	cout << ' ';
                else	cout << map[i][j];
            cout << '\n';
        }	
        cout << '\n';	
    }
    return 0;
}
