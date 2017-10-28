// 该问题可以转换成一个二分图的最大匹配问题，用匈牙利算法。
// 二分图的两个集合为人的第几次喂食和动物数，一边的点个数为人数乘以每个人最多可以喂食的次数，
// 一边的点个数为动物的个数，如果某个人被某动物喜欢，那么代表这个人的某次喂食的所有点都与该
// 动物的点相连。找到最大匹配后，如果最大匹配的边的个数少于动物的个数，
// 则意味着肯定有动物没有被喂食，不存在解决方案；最大匹配的边的个数肯定不会多于二分图中任意
// 一个集合的点的个数，因此，只有最大匹配的边的个数与动物个数相等时输出Yes。

// 匈牙利算法的思想是寻找增广路径，增广路径是指从一个未匹配点开始，边则匹配不匹配相互变换，最后
// 终止于另一未匹配点的路径，很显然，边的匹配部分是一个匹配，边的不匹配部分是另一个匹配，且
// 不匹配边的集合组成的匹配比原先的匹配边的集合大1，将其匹配状态进行反转，获得新的匹配，
// 那么显然到了包含最大匹配的增广路径后，就再也找不到新的增广路径了
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>* feed;
int mat[100][100];
vector<int> matching;   // 若为-1，则不在匹配中，否则其为在匹配中连接的另一顶点
vector<bool> check;     // 若为真，则该点已经被访问过，不会在寻路过程中再次被访问

// 从点u出发有没有增广路
bool crosspath(int u)
{
    // 对于图中顶点u的每条边
    for (auto i = feed[u].begin(); i != feed[u].end(); i++)
    {
        int v = *i; // v是边连接的另一个顶点
        if (!check[v])  // 如果v不在路径中
        {
            check[v] = true;    // 将其放入路径
            if (matching[v] == -1 || crosspath(matching[v]))
            {
                // 如果v未被匹配过，u-v就是找到的增广路径，v与u匹配
                // 如果v在匹配中，我们深度搜索与之匹配的节点是否有新的增广路径
                // （一开始连接v的那条由于v被访问而不会被寻找），如果有，意味着
                // 该路径可以与v和u一起构成新的增广路径，即u-v-matching[v]的新增广路径
                // 递归在以下两个条件终止：
                // 1.crosspath(u0)发现一个未被匹配的点v0时，此时v0与u0匹配，返回真。
                // crosspath(u0)是上一层crosspath(u1)调的crosspath(matching[v1])，
                // 因此在图中u1和v1是相连的，让v1和u1匹配（v1原先和u0匹配，因为原来
                // matching[v1]=u0），也就是说，原先u1-v1->u0-v0变成了u1->v1-u0->v0，匹配
                // 发生了反转，并连锁反应到最开始的调用，并使得匹配的总数+1。
                // 2.crosspath(u0)没有找到增广路径，返回false，于是if判断为假，返回false，
                // 上一层crosspath(u1)调的crosspath(matching[v1])便不影响v1和u0的匹配，
                // 去测试从下一个连接的顶点出发是否可找到增广路。
                // 当再也找不到增广路径时，说明matching数组反应的匹配已经是最大匹配，这是一个定理。
                matching[v] = u;
                return true;
            }
        }
    }    
    return false;   // 不存在增广路径
}

int main()
{
    int m, n;   // m是人数，n是动物数
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int k;
        cin >> k;
        feed = new vector<int>[m * k];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1)
                    for (int kk = 0; kk < k; kk++)
                        feed[i * k + kk].push_back(j);
        int count = 0;
        matching = vector<int>(n, -1);
        for (int i = 0; i < m * k; i++)
        {
            check = vector<bool>(n, false);
            // 从crosspath的函数分析可以看出，每当crosspath返回true时，匹配数+1。
            if (crosspath(i))
                count++;           
        }
        cout << (count == n ? "Yes" : "No") << endl;
        delete[] feed;
    }
    return 0;
}