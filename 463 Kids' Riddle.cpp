#include <iostream>
using namespace std;

int main()
{
	int holes[] = { 1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0 };
	long n;
	int count = 0;
	cin >> n;
	while (n / 16 != 0)
	{
		count += holes[n % 16];
		n /= 16;
	}
	count += holes[n];
	cout << count;
	return 0;
}
