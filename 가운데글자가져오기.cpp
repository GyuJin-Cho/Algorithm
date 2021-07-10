#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

string solution(string s)
{
    string answer = "";
    int a = 0;
    if (s.length() % 2 == 1)
    {
        a = s.length() / 2;
        answer = s[a];
    }
    else
    {
        a = s.length() / 2;
        answer = s[a-1];
        answer += s[a];
    }
    return answer;
}

int main()
{
    cout << solution("qwer");
    return 0;
}