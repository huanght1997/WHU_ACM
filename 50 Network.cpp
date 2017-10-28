// 最小生成树算法
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        int N;
        cin >> N;
        int mat[100][100];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> mat[i][j];
        // 这里用Prim算法
        int adjvex[100], lowcost[100], min, result;
        lowcost[0] = adjvex[0] = result = 0;
        for (int i = 1; i < N; i++)
        {
            lowcost[i] = mat[0][i];
            adjvex[i] = 0;
        }
        for (int i = 1; i < N; i++)
        {
            min = INT_MAX;
            int j = 1, k = 0;
            while (j < N)
            {
                if (lowcost[j] != 0 && lowcost[j] < min)
                {
                    min = lowcost[j];
                    k = j;
                }
                j++;
            }
            result += mat[adjvex[k]][k];
            lowcost[k] = 0;
            for (j = 1; j < N; j++)
            {
                if (lowcost[j] != 0 && mat[k][j] < lowcost[j])
                {
                    lowcost[j] = mat[k][j];
                    adjvex[j] = k;
                }
            }
        }
        cout << result << endl;
    }
}