#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
};

bool cmp(point a, point b)
{
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int main()
{
    int N;
    while (cin >> N)
    {
        vector<point> v1, v2;
        for (int i = 0; i < N; i++)
        {
            point temp;
            cin >> temp.x >> temp.y;
            v1.push_back(temp);
            v2.push_back(temp);
        }
        sort(v1.begin(), v1.end(), cmp);
        int line;  // 分割线为y = line / 2
        if (N % 2 == 0)
            line = v1[v1.size() / 2].y + v1[v1.size() / 2 - 1].y;
        else
            line = v1[v1.size() / 2].y * 2;
        // v2关于线y=line/2做轴对称
        for (int i = 0; i < v2.size(); i++)
        {
            v2[i].y = line - v2[i].y;
        }
        sort(v2.begin(), v2.end(), cmp);
        bool flag = true;
        // 上下对称满足关于线y=line/2轴对称后与原图像重合
        for (int i = 0; i < v2.size() / 2; i++)
            if (v2[i].x != v1[i].x || v2[i].y != v1[i].y)
            {
                flag = false;
                break;
            }
        cout << (flag ? "YES" : "NO") << endl;
    }
}