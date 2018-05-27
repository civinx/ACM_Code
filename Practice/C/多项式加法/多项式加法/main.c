#include <stdio.h>
#include <math.h>

void outNum(int j,int k)
{
    int absk = abs(k);
    if(absk==1 && j!=1 && j!=0)
    {
        printf("x%d",j);
    }
    else if(absk==1 && j!=0)
    {
        printf("x");
    }
    else if(absk==1)
    {
        printf("%d",absk);
    }
    else if(j==0)
    {
        printf("%d",absk);
    }
    else if(j==1)
    {
        printf("%dx",absk);
    }
    else
    {
        printf("%dx%d",absk,j);
    }
    
}

int main()
{
    int num[101] = { (0) };
    int cut = 0;
    int ent = 0;
    int i,j,k;
    while(cut < 2)
    {
        k=0;
        scanf("%d %d",&j,&k);
        num[j] += k;
        if(j==0)
            cut++;
    }
    
    for(i=100;i>-1;i--)
    {
        j=i;
        k=num[j];
        if(k!=0)
        {
            ent++;
            if(cut==2)
            {
                if(k<0)
                    printf("-");
                outNum(j,k);
                cut ++;
            }
            else
            {
                if(k<0)
                {
                    printf("-");
                    outNum(j,k);
                }
                else
                {
                    printf("+");
                    outNum(j,k);
                }
            }
        }
    }
    if(ent==0)
        printf("0");
    
    return 0;
}