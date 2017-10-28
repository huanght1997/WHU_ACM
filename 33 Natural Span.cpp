/*
大于（a-1)*(b-1)的数一定可以用a,b的线性组合来表示。
证明：因为a和b互斥，对于任何大于(a-1)*（b-1)的数c，
一定存在一个k(0<=k<b),使a*k和c同余(mod b)所以c就可以表示为a*k+(（c-a*k)/b)*b 
*/
#include<stdio.h>
#include<stdbool.h>
int main(){
    int a,b,m,n,p,i,j,sum;
    bool flag;
    while(scanf("%d %d %d %d",&a, &b, &m, &n)!=EOF)
    {
        sum=0;
        if (n>(a-1)*(b-1))
        p=(a-1)*(b-1);
        else
        p=n+1;
        for(i=m;i<p;i++)
        {
            flag=false;
            for(j=0;j<=i/b;j++)
            if((i-j*b)%a==0)
            {
                flag=true;
                break;
            }
            if(!flag)
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
