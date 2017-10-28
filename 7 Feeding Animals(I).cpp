#include <iostream>
using namespace std;

int main()
{
	// 这个问题就是说，每个动物有8个人喂，怎么喂能让喂饱所有动物使用的时间的和最少
	// 当然是每个动物都找能最短时间喂饱自己的啊！
	int n;
	while (cin >> n)
	{
		int *min = new int[n];
		// min[i]表示第i个动物喂饱的最短时间
		for (int i = 0; i < n; i++)
			min[i] = 10001;	// 每个人时间不会超过10000，题目说的
		int temp;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> temp;
				if (temp < min[j])
					min[j] = temp;
			}
		// 算和
		int result = 0;
		for (int i = 0; i < n; i++)
			result += min[i];

		cout << result << endl;
		delete[] min;
	}
	return 0;
}