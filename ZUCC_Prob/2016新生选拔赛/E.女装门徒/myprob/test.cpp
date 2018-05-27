#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct x{
    int aa,bb,cc,xa,xb,xc;
    
}data[1005];
int main() {
    int n, m;
    int a,b,c;
    int t;
    int cas=1;
    scanf("%d",&t);
    int index[1005];
    while(t--){
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d%d%d",&data[i].aa,&data[i].bb,&data[i].cc,&data[i].xa,&data[i].xb,&data[i].xc);
            
        }
        int count=0;
        memset(index,0,sizeof(index));
        while(count<n){
            int flag=0;
            for(int i=0;i<n;i++){
                if(index[i]==0&&data[i].aa+a>=data[i].xa&&data[i].bb+b>=data[i].xb&&data[i].cc+c>=data[i].xc){
                    a+=data[i].aa;
                    b+=data[i].bb;
                    c+=data[i].cc;
                    index[i]=1;
                    count++;
                    flag=1;
                }
            }
            if(flag==0)
                break;
        }
        if(count==n){
            printf("Case #%d: Yes\n",cas++);
        }else{
            printf("Case #%d: No\n",cas++);
        }
    }
    return 0;
}
