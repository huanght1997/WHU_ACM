#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
using namespace std;  
int array[110];  
double sigma[110][110], f[110], sign[110][110];  
int main()  
{  
    int T, Ti;  
    cin >> T;  
    for(Ti=1;Ti<=T;Ti++)  
    {  
        int n, p,i,j,k;  
        memset(sign, 0, sizeof sign);  
        scanf("%d %d", &n, &p);  
        for (i = 1; i <= n; ++i)  
            scanf("%d", &array[i]);  
        for (i = 1; i <= n; ++i)//用sigma矩阵的上半边存储i~j的累和   
            for (j = i; j <= n; ++j)  
            {  
                if (j == i)  
                    sigma[i][j] = array[j];  
                else sigma [i][j] = sigma[i][j - 1] + array[j];  
            }  
        for (i = 1; i <= n; ++i)//用sign矩阵的上半边存储i~j的sum of the squared deviation   
            for (j = i; j <= n; ++j)  
            {  
                double mid = sigma[i][j] / (j - i + 1);  
                for (k = i; k <= j; ++k)  
                    sign[i][j] += pow(array[k] - mid,2);  
            }  
        for (i = 1; i <= n; ++i)//设定一个极大的数   
            f[i] = 1e35;  
        f[0] = 0;  
        for (i = 1; i <= n; ++i)  
            for (j = 0; j < i; ++j)  
            {  
                if (i - j < p)  
                    continue;  
                f[i] = min(f[i], f[j] + sign[j + 1][i]);//用动态规划求解最小的squared deviation   
            }  
        if (Ti!=1)  
            puts("");  
        printf("Case %d:\n",Ti);  
        printf("%.2lf\n", f[n]);//f[n]里就是最终答案   
    }  
    return 0;  
}  
