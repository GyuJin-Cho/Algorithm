#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    int length = s.length();
    for(int j=0;j<length;j++)
    {
        stack<char> st;
        for (int i = 0; i < length; i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                continue;
            }
            else if (st.top() == '[')
            {
                if (s[i] == ']')
                {
                    st.pop();
                    continue;
                }
                    

            }
            else if (st.top() == '{')
            {
                if (s[i] == '}')
                {
                    st.pop();
                    continue;
                }
            }
            else if (st.top() == '(')
            {
				if (s[i] == ')')
				{
                    st.pop();
                    continue;
				}
            }
        	st.push(s[i]);
            
        }
        if (st.empty())
            answer++;
        char ch = s.front();
        s.erase(s.begin());
        s.push_back(ch);
    }
    

    return answer;
}

int main()
{
    cout << solution("[](){}");

    return 0;
}