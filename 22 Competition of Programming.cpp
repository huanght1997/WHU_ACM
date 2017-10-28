/* 
 * Author: stormdpzh 
 * Created Time: 2012/7/14 15:21:06 
 * File Name: woj_1022.cpp 
 */  
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
#include <algorithm>  
#include <functional>  
  
#define sz(v) ((int)(v).size())  
#define rep(i, n) for(int i = 0; i < n; i++)  
#define repf(i, a, b) for(int i = a; i <= b; i++)  
#define repd(i, a, b) for(int i = a; i >= b; i--)  
#define out(n) printf("%d\n", n)  
#define mset(a, b) memset(a, b, sizeof(a))  
#define wh(n) while(1 == scanf("%d", &n))  
#define whz(n) while(1 == scanf("%d", &n) && n != 0)  
#define lint long long  
  
using namespace std;  
  
const int MaxN = 3005;  
  
struct Node {  
    int t, c;  
    bool operator < (const Node &tmp) const {  
        return c > tmp.c;  
    }  
};  
Node node[MaxN];  
int n;  
bool vis[MaxN];  
  
int gao()  
{  
    int res = 0;  
    mset(vis, false);  
    rep(i, n) {  
        bool ok = false;  
        repd(j, node[i].t, 1) {  
            if(!vis[j]) {  
                vis[j] = true;  
                ok = true;  
                break;  
            }  
        }  
        if(!ok) res += node[i].c;  
    }  
    return res;  
}  
  
int main()  
{  
    int t;  
    scanf("%d", &t);  
    int ans = 1;  
    wh(n) {  
        if(ans > 1) puts("");  
        printf("Case %d:\n", ans++);  
        rep(i, n)   
            scanf("%d%d", &node[i].t, &node[i].c);  
        sort(node, node + n);  
        out(gao());  
    }  
    return 0;  
}  