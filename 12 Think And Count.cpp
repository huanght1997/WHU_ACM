#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N, M;   // N为行数，M为列数
    long min, p;
    // combo为到某列时的连续白色方块数，sum为到该行时以该列的方形为右下角的长方形个数
    vector<int> combo;
    vector<long long> sum, pre;
    long long out;  
    while (cin >> N >> M)
    {
        combo = vector<int>(M+1, 0);
        pre = vector<long long>(M+1, 0);
        sum = vector<long long>(M+1, 0);
        out = 0LL;
        for (int row = 1; row <= N; row++)
        {
            // 执行对combo数组的初始化
            for (int col = 1; col <= M; col++)
            {
                char temp;
                cin >> temp;
                if (temp == 'w')    // 如果该行的列是白色，则连续白色方块数+1
                    combo[col]++;
                else
                    combo[col] = 0;  // 否则清零（想起了连击时漏了一个的痛苦吗）
            }
            for (int col = 1; col <= M; col++)
            {
                if (combo[col] >= combo[col-1])
                {
                    // 如果这一列的连续白方块比前面一列的白色方块多，那么直接加上
                    // 试想一下，如果这种情况发生，如果前面是白，那么前面的右下角矩形
                    // 都满足其右边还是白色（因为这边连续白方块多），所以都可以往右
                    // 延伸一格即sum[col-1]，再加上这一单列以其为右下角的有combo[col]个
                    // 其他情况？不存在的。前面是黑？那它combo就是0了不满足条件。
                    sum[col] = sum[col - 1] + combo[col];
                    // 前面这一个就是比自己的combo少的，233333
                    pre[col] = 0;
                }
                else
                {
                    // 如果这一列的连续白方块比前面的少呢？那么往前找，直到找到combo比自己小的
                    // 如果没有找到，那么以其为右下角的矩形的个数就是连续白方块数乘以列数
                    // 如果找到了，来源就有2个：一个在找到的列的右边，个数是右边的列数乘以连续白方块数
                    // 一个在找到的列及其左边，是该列sum代表的长方形向右一直扩展的结果。
                    // 这小列即是p-1，pre数组表示往前看多少才可能找到比自己少的，以减少无用的遍历
                    
                    // 显然，比自己combo少的无论如何不管怎样比前面的那列少，pre值+1
                    pre[col] = pre[col - 1] + 1;
                    // 大跃进
                    int p = col - pre[col];
                    // 如果发现离其最近的可能列combo比自己大，那就再前面可能比自己combo小的最近就是
                    // p-1的pre了
                    while (p > 0 && combo[p - 1] >= combo[col])
                        p = p - pre[p - 1] - 1;
                    // 没有找到，自己combo最小
                    if (p <= 0)
                    {
                        sum[col] = combo[col] * col;
                        pre[col] = 0;
                    }
                    else
                    {
                        // 找到了，p-1列是比自己小的,记下pre造福后人
                        // +1和-1注意一下，这里有点绕
                        sum[col] = combo[col] * (col - p + 1) + sum[p - 1];
                        pre[col] = col - p - 1;
                    }
                }
                // 该行该列的所有右下角矩形加入！
                out += sum[col];
            }
        }
        cout << out << endl;
    }
    return 0;
}