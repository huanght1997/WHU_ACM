// 这里的结果（不整除2016）为max(S)*2^(n-1)，n为S的元素个数,max(S)为S中最大的数
// 把所有的集合分成包含max(S)和不包含max(S)这两类就知道原因了。
#include <iostream>
#include <climits>

using namespace std;

int mod(int a, int b, int n);
int main()
{
    int N;
    while (cin >> N && N > 0)
    {
        // 找最大值
        int max = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            if (tmp > max)
                max = tmp;
        }
        // 接下来是大数取模的问题，写在函数内，用反复平方法，或者叫Montgomery算法。
        // 另外，(a*b)%c=(a%p*b%p)%p
        cout << mod(mod(max, 1, 2006) * mod(2, N - 1, 2006), 1, 2006) << endl;
    }
    return 0;
}

int mod(int a, int b, int n)
{
    // 计算(a^b)%n的值
    int result = 1;
    int base = a;
    while (b > 0)
    {
        if (b & 1)
            result = (result * base) % n;
        base = (base * base) % n;
        b >>= 1;
    }
    return (result + n) % n;
}