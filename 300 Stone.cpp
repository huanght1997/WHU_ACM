#include <iostream>
using namespace std;

int main()
{
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        int n;
        cin >> n;
        if (n % 7 == 1 || n % 7 == 0)
            cout << "Dzs" << endl;
        else
            cout << "Sproblvem" << endl;
    }
    return 0;
}
