//首先找出序列中所有的置换，然后对于每个置换有两种方法将其调成合法。  
//1.每次用置换中最小的数去和其他数换，ans=sum+min*(num-2）。  
//2.用全局最小的元素换所有元素，最后还要把这个元素换出去，ans=sum+allmin*(num+1)。  
//对于每个置换两种方案取min值相加就可以了。  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <math.h>  
#include<iostream>  
using namespace std;  
int h1[65537];//存储数所在的位置  
int h2[65537];//金刚想要数所在的位置  
int a[5001];  //第一行数  
int b[5001];  //第二行数  
bool sign[5001];//标记这个数是否移动到所想位置  
int main()  
{  
    int n, i, k, tp, cost, q;  
    int min;  
    while (scanf("%d", &n) != EOF && n != 0)  
    {  
        min = 65538;  
        memset(sign, 0, sizeof(sign));  
        cost = 0;  
        for (i = 1; i <= n; i++)  
        {  
            scanf("%d", &a[i]);  
            if (a[i] < min) min = a[i];  
            cost += a[i];//每个数都至少要交换一次  
            h1[a[i]] = i;  
        }  
        for (i = 1; i <= n; i++)  
        {  
            scanf("%d", &b[i]);  
            h2[b[i]] = i;  
        }  
        for (i = 1; i <= n; i++)  
            if (!sign[i])  
            {  
                tp = 65538;//记录循环中最小的数  
                q = i;  
                k = 0;//循环个数  
                do//找到循环个数和循环中最小的数  
                {  
                    sign[q] = true;  
                    if (b[q] < tp)  
                        tp = b[q];  
                    q = h1[b[q]];  
                    k++;  
                }while (q != i);  
                cost += (k - 2) * tp < tp + (k + 1) * min ? (k - 2) * tp : tp + (k + 1) * min;//两种方式中选择小的  
            }  
        printf("%d\n", cost);  
    }  
    return 0;  
}  