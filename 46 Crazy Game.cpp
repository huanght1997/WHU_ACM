#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int Ti = 1; Ti <= T; Ti++)
    {
        int N;
        cin >> N;
        int* arr = new int[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int count = 0;
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < N - i - 1; j++)
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    count++;
                }
        cout << count << endl;
    }
    return 0;
}