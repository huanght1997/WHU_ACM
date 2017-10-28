// 不说了，最短路径，Dijkstra算法
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct road {
    int pguard;
    int sguard;
    int cost;
    char letter;
};
struct graph {
    int v;  // 顶点数
    int e;  // 边数
    road roads[100][100];   // 邻接矩阵
};
graph g;
int plovers, slovers;
void dijkstra(int v);
int main()
{
    while (cin >> g.v >> g.e)
    {
    road def = {INT_MAX, INT_MAX, INT_MAX, 0};
    for (int i = 0; i < g.v; i++)
        for (int j = 0; j < g.v; j++)
            g.roads[i][j] = def;
    for (int i = 0; i < g.e; i++)
    {
        road temp;
        int u, v;
        cin >> u >> v >> temp.pguard >> temp.sguard >> temp.cost;
        cin.get();
        cin.get(temp.letter);
        g.roads[u][v] = temp;
        g.roads[v][u] = temp;
    }
    cin >> plovers >> slovers;
    dijkstra(0);
    }
    return 0;
}
// 算法抄袭自武大的数据结构教材，注意对是否有路的判断
void dijkstra(int v)
{
    int dist[100], path[100], s[100];
    int mindis, i, j, u;
    for (i = 0 ; i < g.v; i++)
    {
        s[i] = 0;
        if (g.roads[v][i].pguard < plovers && g.roads[v][i].sguard < slovers)
        {
            path[i] = v;
            dist[i] = g.roads[v][i].cost;
        }
        else
        {
            path[i] = -1;
            dist[i] = INT_MAX;
        }           
    }
    s[v] = -1; path[v] = 0;
    for (i = 0; i < g.v; i++)
    {
        mindis = INT_MAX;
        for (j = 0; j < g.v; j++)
            if (s[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        s[u] = 1;
        for (j = 0; j < g.v; j++)
            if (s[j] == 0)
                if (g.roads[u][j].pguard < plovers && g.roads[u][j].sguard < slovers
                    && dist[u] + g.roads[u][j].cost < dist[j])
                    {
                        dist[j] = dist[u] + g.roads[u][j].cost;
                        path[j] = u;
                    }
    }
    int apath[100], d, k;
    if (s[g.v-1]==1&&g.v-1!=v)
    {
        d = 0; apath[d] = g.v-1;
        k = path[g.v-1];
        while (k != v)
        {
            apath[++d] = k;
            k = path[k];
        }
        apath[++d] = v;
        for (j = d; j > 0; j--)
            cout << g.roads[apath[j]][apath[j-1]].letter;
        cout << endl;
    }
}
