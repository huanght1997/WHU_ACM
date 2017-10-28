#include <iostream>
using namespace std;

int main()
{
    int m, p, n;
    while (cin >> m >> p >> n && !(p == 0 && m == 0 && n == 0))
        cout << (p * n > m ? p * n : m) << endl;
    return 0;
}
