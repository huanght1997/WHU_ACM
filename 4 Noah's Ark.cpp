#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	const double threshhold = 1e-9;
	const double INCHES_PER_CUBIT = 18.0;
	const double CM_PER_CUBIT = 45.72;
	const double METERS_PER_CUBIT = CM_PER_CUBIT / 100.0;
	const double FEET_PER_CUBIT = INCHES_PER_CUBIT / 12.0;
	double length, width;
	string ldw, wdw, tmp;
	while (cin >> length >> ldw >> width >> wdw)
	{
		// 过滤掉没用的高度和空行
		getline(cin, tmp);
		getline(cin, tmp);

		if (ldw == "meters")
			length /= METERS_PER_CUBIT;
		else if (ldw == "centimeters")
			length /= CM_PER_CUBIT;
		else if (ldw == "inches")
			length /= INCHES_PER_CUBIT;
		else if (ldw == "feet")
			length /= FEET_PER_CUBIT;

		if (wdw == "meters")
			width /= METERS_PER_CUBIT;
		else if (wdw == "centimeters")
			width /= CM_PER_CUBIT;
		else if (wdw == "inches")
			width /= INCHES_PER_CUBIT;
		else if (wdw == "feet")
			width /= FEET_PER_CUBIT;

		if (fabs(length - width) < threshhold)
			cout << "Spin" << endl << endl;
		else if (fabs(length - width * 6.0) < threshhold)
			cout << "Excellent" << endl << endl;
		else
			cout << "Neither" << endl << endl;

	}
	return 0;
}