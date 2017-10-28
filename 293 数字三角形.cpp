#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int M, N;
    while (cin >> M >> N && !(M == 0 && N == 0))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int result = M + (N - i) * (N - i - 1) / 2;
                result += j * (N + 1 - i) + j * (j - 1) / 2;
                cout << setw(2) << result << " ";
            }
            cout << endl;
        }
	cout << endl;
    }
    return 0;
}
