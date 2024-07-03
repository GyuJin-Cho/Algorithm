#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else if (st.top() == '(')
        {
            if (s[i] == ')')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main()
{
    cout << solution("(()(");

    return 0;
}