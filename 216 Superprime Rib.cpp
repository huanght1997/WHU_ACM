#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool check_prime(int n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int N;
	while (cin >> N)
	{
		queue<int> q;
		q.push(2);
		q.push(3);
		q.push(5);
		q.push(7);
		for (int i = 1; i < N; i++)
		{
			while (q.front() < pow(10, i))
			{
				int prefix = q.front();
				for (int j = 0; j < 5; j++)
				{
					int temp = q.front() * 10 + j * 2 + 1;
					if (check_prime(temp))
					{
						q.push(temp);
					}
				}
				q.pop();
			}
		}
		while (!q.empty())
		{
			cout << q.front() << endl;
			q.pop();
		}
	}
	return 0;
}
