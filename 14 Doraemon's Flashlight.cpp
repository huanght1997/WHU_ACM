// 如果学过高数，知道向量的混合积，那么很容易得出结果是
// 给出的矩阵对应的行列式的值的绝对值
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int m[3][3];
    while (scanf("%d %d %d", &m[0][0], &m[0][1], &m[0][2]) == 3)
    {
        scanf("%d %d %d", &m[1][0], &m[1][1], &m[1][2]);
        scanf("%d %d %d", &m[2][0], &m[2][1], &m[2][2]);
        double result = m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1]
                      - m[0][2]*m[1][1]*m[2][0] - m[0][1]*m[1][0]*m[2][2] - m[0][0]*m[1][2]*m[2][1];
        printf("%.2f\n", fabs(result));
    }
    return 0;
}