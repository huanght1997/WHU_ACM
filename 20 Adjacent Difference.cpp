#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<int> seq(N);
        vector<int> adj_seq(N);
        cin >> seq[0];
        adj_seq[0] = seq[0];
        for (int j = 1; j < N; j++)
        {
            cin >> seq[j];
            adj_seq[j] = seq[j] - seq[j - 1];
        }
        sort(adj_seq.begin(), adj_seq.end());
        cout << "Case " << i + 1 << ":" << endl;
        cout << adj_seq[0];
        for (int j = 1; j < N; j++)
            cout << " " << adj_seq[j];
        if (i != T - 1)
            cout << endl << endl;
    }
    return 0;
}