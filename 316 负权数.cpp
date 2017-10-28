#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0))
    {
        stack<char> st;
        if (a == 0)
        {
            cout << 0 << endl;
            continue;
        }
        while (a != 0)
        {
            // assume R < 0
            if (a < 0 && (-a) % (-b) != 0)
            {
                int out = a - (a / b + 1) * b;
                st.push(out >= 10 ? 'A' + out - 10 : out + '0');
                a = a / b + 1;
            }
            else
            {
                int out = a - a / b * b;
                st.push(out >= 10 ? 'A' + out - 10 : out + '0');
                a = a / b;
            }
        }
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}
