#include <iostream>
#include <map>
#include <string>
using namespace std;

#define AddPerson(name, age, generation) (peopleMap[name] = make_pair(age, generation))

// 第一个int表示岁数，-1为还没死，第二个int为辈数，儿子的辈数是父亲的辈数+1。
typedef pair<int, int> person;

int main()
{
	// 这里闲得蛋疼用map
	map<string, person> peopleMap;
	AddPerson("Adam", 930, 1);
	AddPerson("Seth", 912, 2);
	AddPerson("Enosh", 905, 3);
	AddPerson("Kenan", 910, 4);
	AddPerson("Mahalalel", 895, 5);
	AddPerson("Jared", 962, 6);
	AddPerson("Enoch", 365, 7);
	AddPerson("Methuselah", 969, 8);
	AddPerson("Lamech", 777, 9);
	AddPerson("Noah", -1, 10);
	AddPerson("Shem", -1, 11);
	AddPerson("Ham", -1, 11);
	AddPerson("Japheth", -1, 11);

	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << (peopleMap[s1].second < peopleMap[s2].second ? "Yes" : "No") << endl;
		if (peopleMap[s1].first == -1 || peopleMap[s2].first == -1)
			cout << "No enough information" << endl;
		else
			cout << (peopleMap[s1].first > peopleMap[s2].first ? "Yes" : "No") << endl;
	}
	return 0;
}