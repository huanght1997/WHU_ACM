#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << ((n % 14) ? "flymouse" : "snoopy") << " wins the game!" << endl;
    }
    return 0;
}