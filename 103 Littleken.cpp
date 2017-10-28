#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int Ti = 0; Ti < T; Ti++)
    {
        int N;
        scanf("%d%%", &N);
        double p = N / 100.0;
        double pp = p * p / (p * p + (1 - p) * (1 - p));
        printf("%.2f%%\n", pp * 100.0);
    }
    return 0;
}