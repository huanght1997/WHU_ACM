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
        int **chessboard = new int*[N];
        int **dp = new int*[N];
        for (int i = 0; i < N; i++)
        {
            chessboard[i] = new int[N];
            dp[i] = new int[N];
            for (int j = 0 ; j < N; j++)
            {
                cin >> chessboard[i][j];
                if (i == 0)
                    dp[i][j] = chessboard[i][j];
            }
        }
        for (int i = 1; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (j == 0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]);
                else if (j == N-1)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);
                else
                    dp[i][j] = max(max(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]);
                dp[i][j] += chessboard[i][j];
            }
        int result = -1;
        cout << "Case " << Ti << ":" << endl;
        for (int i = 0; i < N; i++)
        {
            if (dp[N-1][i] > result)
                result = dp[N-1][i];
        }
        cout << result << endl;
        if (Ti != T)
            cout << endl;
        for (int i = 0; i < N; i++)
        {
            delete[] dp[i];
            delete[] chessboard[i];
        }
        delete[] dp;
        delete[] chessboard;
    }
}
