#include<stdio.h>
#include<math.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int n,m,j;
        double k;
        scanf("%d",&n);
        if(n==1)
            m=0;
        else{
            k=log(n)/log(2);
            j=k;
            if(k==j)
                m=k;
            else
                m=k/1+1;}
        printf("Case #%d: %d\n",i,m);                                                                  
    }
    return 0;
}
