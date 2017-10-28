#include <iostream>
#include <map>
#include <string>
using namespace std;

int comp(string s1, string s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] == s2[i])
            i++;
        else
            break;
    }
    return i;
}
int main()
{
    int n;
    map<int, string> people;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id;
        string name;
        cin >> id >> name;
        people.insert(pair<int, string>(id, name));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        int result = 0;
        for (int j = 0; j < q; j++)
        {
            int id1, id2;
            cin >> id1 >> id2;
            string s1, s2;
            s1 = people[id1];
            s2 = people[id2];
            result += comp(s1, s2);
        }
        cout << result << endl;
    }
    return 0;
}
