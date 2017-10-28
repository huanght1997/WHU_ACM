// 这种几何学的东西放注释里讲太复杂了……
// 结果简单来说，就是8*面积*面积/(a*b*c)，面积可以用海伦-秦九韶公式计算
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        // 计算边长
        double a, b, c, p;
        a = sqrt(pow(x2-x1,2)+pow(y2-y1,2));    // 这里用pow就对，用乘法就错，可能是溢出？
        b = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
        c = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
        p = (a + b + c) / 2.0;
        double area2 = p * (p - a) * (p - b) * (p - c);
        double result = 8 / (a * b * c) * area2;    
        cout << setiosflags(ios::fixed) << setprecision(3)
            << result << endl;
    }
    return 0;
}