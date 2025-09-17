#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        stack<char> s;
        string p;
        cin >> p;
        for (size_t j = 0; j < p.length(); j++)
        {
            if (p[j] == '(')
                s.push('(');
            else
            {
                if (!s.empty())
                {
                    if (s.top() == '(')
                        s.pop();
                    else
                    {
                        s.push(p[j]);
                    }
                }
                else
                    s.push(p[j]);
            }
        }
        if (!s.empty())
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}
