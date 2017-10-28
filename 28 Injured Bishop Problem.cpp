#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++)
    {
        int N;
        cin >> N;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int diffx = abs(x1 - x2);
        int diffy = abs(y1 - y2);
        cout << "Case " << Ti << ":" << endl;
        if ((diffx - diffy) % 2 != 0)
            cout << -1 << endl;
        else
            cout << max(diffx, diffy) << endl;
        if (Ti != T)
            cout << endl;
    }
    return 0;
}
