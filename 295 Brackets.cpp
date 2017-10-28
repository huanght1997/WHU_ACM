#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cout << "Case " << i + 1 << ": ";
        char ch;
        bool flag = true;
        stack<char> st;
        while (cin.get(ch) && ch != '\n')
        {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if (ch == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    cout << "Illegal" << endl;
                    flag = false;
                    break;
                }
                else
                    st.pop();
            }
            else if (ch == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    cout << "Illegal" << endl;
                    flag = false;
                    break;
                }
                else
                    st.pop();
            }
            else if (ch == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    cout << "Illegal" << endl;
                    flag = false;
                    break;
                }
                else
                    st.pop();
            }
        }
        if (flag)
            cout << (st.empty() ? "Legal" : "Illegal") << endl;
        else
            while (cin.get() != '\n') continue;
    }
    return 0;
}
