#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        int *arr = new int[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        sort(arr, arr + N);
        cout << arr[0];
        int prev = arr[0];
        for (int i = 1; i < N; i++)
        {
            if (arr[i] != prev)
            {
                cout << " " << arr[i];
                prev = arr[i];
            }
        }
        cout << endl;
    }
    return 0;
}