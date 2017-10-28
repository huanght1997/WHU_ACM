#include <iostream>
using namespace std;

int score(double x, double y)
{
    double distance = x * x + y * y;
    if (distance <= 3 * 3)
        return 100;
    else if (distance <= 6 * 6)
        return 80;
    else if (distance <= 9 * 9)
        return 60;
    else if (distance <= 12 * 12)
        return 40;
    else if (distance <= 15 * 15)
        return 20;
    else
        return 0;
}

int main()
{
    double pos[12];
    while (true)
    {
        for (int i = 0; i < 12; i++)
            cin >> pos[i];
        if (pos[0] == -100)
            return 0;
        int p1, p2;
        p1 = score(pos[0], pos[1]) + score(pos[2], pos[3]) + score(pos[4], pos[5]);
        p2 = score(pos[6], pos[7]) + score(pos[8], pos[9]) + score(pos[10], pos[11]);
        cout << "SCORE: " << p1 << " to " << p2 << ", ";
        if (p1 == p2)
            cout << "TIE." << endl;
        else if (p1 < p2)
            cout << "PLAYER 2 WINS." << endl;
        else
            cout << "PLAYER 1 WINS." << endl;
    }
    return 0;
}
