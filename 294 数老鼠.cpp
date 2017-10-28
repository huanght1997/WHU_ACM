/**************************************** 
定义三种老鼠： 
A：成年鼠 
B：小鼠 
C：半年鼠（6个月大的老鼠） 
 
题目的意思转化为： 
一对 A 鼠每6个月产生 2 对 B 鼠； 
一对 B 鼠经过 6 个月变成一对 C 鼠； 
一对 C 鼠经过 6 个月变为一对 A 鼠，同时产下 2 对 B 鼠。 
定义一个变量 nHalfYears ，表示经过了多少半年。 
定义一个变量 sum ，表示经过 nHalfYears 半年后老鼠的总数。列表如下： 
nHalfYears               sum 
0                        B         
1                        C 
2                        A+2B 
3                        A+2B+2C 
4                        3A+6B+2C 
5                        5A+10B+6C 
6                        11A+22B+10C 
7                        21A+42B+22C 
8                        43A+86B+42C 
·                       · 
·                       · 
·                       · 
n                        an A + bn B + cnC 
找规律，得出： 
bn = (an-1 + cn-1)*2 
cn-1=bn-2 
an-1=bn-1/2 
所以得出==》 
bn=(bn-1/2 + bn-2)*2 = bn-1+2*bn-2 
sum = (3/2)*bn + bn-1 
****************************************************/  
#include <stdio.h>  
int main(){  
    long long b[31]={0};  
    b[2]=2;  
    b[3]=2;  
    int Case,nYears,nHalfYears;  
    long long sum;  
    for(int i=4;i<=30;i++)      
        b[i]=b[i-1]+2*b[i-2];  
    scanf("%d",&Case);  
    while (Case--){  
        scanf("%d",&nYears);  
        nHalfYears=2*nYears;   
        sum=3*b[nHalfYears]/2+b[nHalfYears-1];  
        printf("%lld\n",sum);  
    }  
    return 0;  
}
