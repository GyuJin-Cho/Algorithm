#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;

    for(int i=0;i<s.length();i++)
    {
        if (s[i] == '(')
            st.push('(');
        else
        {
	        if(!st.empty()&&st.top()=='(')
	        {
                st.pop();
	        }
            else
            {
                st.push(')');
            }
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    cout << solution(")()(");
    return 0;
}