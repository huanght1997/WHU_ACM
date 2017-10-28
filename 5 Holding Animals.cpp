// 典型的0-1背包问题，动态规划
#include <iostream>
using namespace std;
int findMax(int sizes[], int points[], int n, int s);

int main()
{
	// n表示动物的种类
	int n;
	while (cin >> n)
	{
		// sizes[i]和points[i]分别表示第i+1种动物的大小和点数
		int *sizes = new int[n];
		int *points = new int[n];
		for (int i = 0; i < n; i++)
			cin >> sizes[i] >> points[i];
		// s 表示诺亚方舟的大小
		int s;
		cin >> s;
		cout << findMax(sizes, points, n, s) << endl;
		delete[] sizes;
		delete[] points;
	}
	return 0;
}

int findMax(int sizes[], int points[], int n, int s)
{
	// M[i]表示对当背包大小为i时可以得到的最大点数
	int *M = new int[s + 1];
	for (int i = 0; i < s + 1; i++)
		M[i] = 0;
	// for循环开始前，M存的是如果只放前j件，所有对应的背包大小可以得到的最大点数
	for (int j = 0; j < n; j++)
		for (int i = s; i > 0; i--)
			// 如果第j+1件能够放下，M[i]为不放下第j+1件的最大点数，
			// M[i - sizes[j]] + points[j]为放下第j+1件的最大点数，取最大值更新M
			// 该更新的M显然不会被i更小的时候用到，所以空间可以压缩成一个一维数组
			if (i >= sizes[j] && M[i] < M[i - sizes[j]] + points[j])
				M[i] = M[i - sizes[j]] + points[j];
	int result = M[s];
	delete[] M;
	return result;
}
