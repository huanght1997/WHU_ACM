// 很普通的题目，随便怎样都好
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        cin.get();  // 去除回车
        string courses[5][7];
        for (int i = 0; i < n; i++)
        {
            string temp;
            int colon_pos;
            int day, class_num;

            getline(cin, temp);
            colon_pos = temp.find(':');
            switch (temp[colon_pos + 2])
            {
            case 'M':
                day = 0;
                break;
            case 'T':
                day = temp[colon_pos + 3] == 'U' ? 1 : 3;
                break;
            case 'W':
                day = 2;
                break;
            case 'F':
                day = 4;
                break;
            default:
                break;
            }
            class_num = temp[temp.length() - 1] - '0' - 1;
            class_num += temp[colon_pos + 6] == 'M' ? 0 : 4;
            courses[day][class_num] = temp.substr(0, colon_pos);
            int blank = (11 - colon_pos) / 2;
            courses[day][class_num].append(blank + 1 - (colon_pos & 1), ' ');
        }
        cout << "+-----+-----------+-----------+-----------+-----------+-----------+" << endl;
        cout << "|     |    MON    |    TUE    |    WED    |    THU    |    FRI    |" << endl;
        cout << "+-----+-----------+-----------+-----------+-----------+-----------+" << endl;
        cout << "|                          Morning                                |" << endl;
        cout << "+-----+-----------+-----------+-----------+-----------+-----------+" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "|  " << i+1 << "  |";
            for (int j = 0; j < 5; j++)
            {
                cout << right << setw(11) << courses[j][i] << "|";
            }
            cout << endl;
            cout << "+-----+-----------+-----------+-----------+-----------+-----------+" << endl;
        }
        cout << "|                         Afternoon                               |" << endl;
        cout << "+-----+-----------+-----------+-----------+-----------+-----------+" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "|  " << i+1 << "  |";
            for (int j = 0; j < 5; j++)
            {
                cout << right << setw(11) << courses[j][i + 4] << "|";
            }
            cout << endl;
            cout << "+-----+-----------+-----------+-----------+-----------+-----------+" << endl;
        }
        cout << endl;
    }
    return 0;
}