#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <functional>

#define sz(v) ((int)(v).size())
#define rep(i, n) for(int i = 0; i < n; i++)
#define repf(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define out(n) printf("%d\n", n)
#define mset(a, b) memset(a, b, sizeof(a))
#define lint long long

using namespace std;

const int INF = 1 << 30;
const int MaxN = 105;
const double eps = 1e-9;
const int chash = 12343;
const double pie = acos(-1.0);

int n, nodes;
double x[MaxN], y[MaxN], r[MaxN];
double ans;
int l_link[10 * MaxN], nextt[10 * MaxN];
double node[10 * MaxN][2];
int first[chash + 5];

int sgn(double d)
{
    if(d > eps) return 1;
    if(d < -eps) return -1;
    return 0;
}

struct Inter
{
    double x, y;
    Inter() {}
    bool operator < (const Inter &t) const {
        if(sgn(x - t.x) == 0) return (y < t.y);
        else return x < t.x;
    }
};
Inter inter[MaxN];

double get_dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void init()
{
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
        r[i] = 1.0;
    }
    bool b[MaxN];
    mset(b, true);
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(sgn(x[i] - x[j]) == 0 && sgn(y[i] - y[j]) == 0 && sgn(r[i] - r[j]) == 0) {
                b[i] = false;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j && sgn(r[i] - r[j]) < 0) {
                if(sgn(get_dist(x[i], y[i], x[j], y[j]) - (r[j] - r[i])) <= 0) {
                    b[i] = false;
                    break;
                }
            }
        }
    }
    int j = 0;
    for(int i = 1; i <= n; i++) {
        if(b[i]) {
            j++;
            x[j] = x[i];
            y[j] = y[i];
            r[j] = r[i];
        }
    }
    n = j;
}

double get_angle(double x, double y)
{
    if(sgn(x) < 0) return atan(y / x) + pie;
    else if(sgn(x) > 0) {
        if(sgn(y) > 0) return atan(y / x);
        else return atan(y / x) + pie * 2.0;
    }
    else if(sgn(y) > 0) return pie / 2.0;
    else return pie * 3.0 / 2.0;
}

void get_cross(int i, int j, double &t1, double &t2)
{
    double a, b, c, a1, b1, c1, x1, y1, x2, y2, t, l;
    a = (x[i] - x[j]) * 2.0;
    b = (y[i] - y[j]) * 2.0;
    c = r[j] * r[j] - r[i] * r[i] + x[i] * x[i] - x[j] * x[j] + y[i] * y[i] - y[j] * y[j];
    a1 = b;
    b1 = -a;
    c1 = a1 * x[i] + b1 * y[i];
    t = a * b1 - b * a1;
    x1 = (c * b1 - b * c1) / t;
    y1 = (a * c1 - c * a1) / t;
    l = sqrt(r[i] * r[i] - (x1 - x[i]) * (x1 - x[i]) - (y1 - y[i]) * (y1 - y[i]));
    t = sqrt(a1 * a1 + b1 * b1);
    x2 = x1 + l * a1 / t;
    y2 = y1 + l * b1 / t;
    x1 = x1 * 2.0 - x2;
    y1 = y1 * 2.0 - y2;
    t1 = get_angle(x1 - x[i], y1 - y[i]);
    t2 = get_angle(x2 - x[i], y2 - y[i]);
    if(sgn(t2 - t1) < 0) t1 = t1 - pie * 2.0;
    t = (t1 + t2) / 2.0;
    if((get_dist(x[j], y[j], x[i] + r[i] * cos(t), y[i] + r[i] * sin(t)) - r[j]) > 0) {
        t = t1;
        t1 = t2;
        t2 = t;
        if(sgn(t2) <= 0) t2 = t2 + pie * 2.0;
        else t1 = t1 - pie * 2.0;
    }
}

int get_index(double x, double y)
{
    int i, t;
    t = (int)(fabs(x + y + eps) * 100000) % chash;
    i = first[t];
    while(i != 0) {
        if(sgn(node[i][0] - x) == 0 && sgn(node[i][1] - y) == 0) {
            return i;
        }
        i = nextt[i];
    }
    nodes++;
    node[nodes][0] = x;
    node[nodes][1] = y;
    nextt[nodes] = first[t];
    first[t] = nodes;
    return nodes;
}

double get_chord(double r, double a)
{
    return r * r / 2.0 * (a - sin(a));
}

void get_node()
{
    int i, j, k, top, t1, t2;
    nodes = 0;
    for(i = 1; i <= n; i++) {
        top = 0;
        for(j = 1; j <= n; j++) {
            if(i != j && sgn(get_dist(x[i], y[i], x[j], y[j]) - (r[i] + r[j])) < 0) {
                top++;
                get_cross(i, j, inter[top].x, inter[top].y);
            }
        }
        if(top > 0) {
            sort(inter + 1, inter + top + 1);
            k = 0;
            for(j = 1; j <= top; j++) {
                if(k == 0 || sgn(inter[j].x - inter[k].y) > 0) {
                    k++;
                    inter[k].x = inter[j].x;
                    inter[k].y = inter[j].y;
                }
                else {
                    if(sgn(inter[j].y - inter[k].y) > 0) {
                        inter[k].y = inter[j].y;
                    }
                }
            }
            top = k;
            while(top > 0 && sgn(inter[top].y - (inter[1].x + pie * 2.0)) >= 0) {
                if(sgn(inter[top].x - pie * 2.0 - inter[1].x) < 0) {
                    inter[1].x = inter[top].x - pie * 2.0;
                }
                top--;
            }
            if(top > 0) {
                for(j = 1; j <= top - 1; j++) {
                    ans += get_chord(r[i], inter[j + 1].x - inter[j].y);
                    t1 = get_index(x[i] + r[i] * cos(inter[j + 1].x), y[i] + r[i] * sin(inter[j + 1].x));
                    t2 = get_index(x[i] + r[i] * cos(inter[j].y), y[i] + r[i] * sin(inter[j].y));
                    l_link[t1] = t2;
                }
                ans = ans + get_chord(r[i], inter[1].x + pie * 2.0 - inter[top].y);
                t1 = get_index(x[i] + r[i] * cos(inter[1].x), y[i] + r[i] * sin(inter[1].x));
                t2 = get_index(x[i] + r[i] * cos(inter[top].y), y[i] + r[i] * sin(inter[top].y));
                l_link[t1] = t2;
            }
        }
        else {
            ans += pie * r[i];
        }
    }
}

void gao()
{
    int i, j;
    bool vis[MaxN * 10];
    ans = 0.0;
    get_node();
    mset(vis, false);
    for(int i = 1; i <= nodes; i++) {
        if(!vis[i]) {
            j = i;
            do {
                vis[j] = true;
                ans += (node[l_link[j]][0] * node[j][1] - node[j][0] * node[l_link[j]][1]) / 2;
                j = l_link[j];
            } while(j != i);
        }
    }
}

int main()
{
    while(1 == scanf("%d", &n)) {
        init();
        gao();
        printf("%.2lf\n", ans);
    }
    return 0;
}
