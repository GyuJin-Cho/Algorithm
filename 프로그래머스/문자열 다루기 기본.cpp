#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    bool check = false;
    if (s.length() == 4)
        check = true;
    if (s.length() == 6)
        check= true;
    if(check)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {
                continue;
            }
            else
            {
                answer= false;
            }
        }
    }
    if (!check)
        return check;
    return answer;
}

int main()
{
    cout << solution("a234");
    return 0;
}