#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string s)
{
    int i = 1;
    s[0] = toupper(s[0]);

    while(s[i]!='\0')
    {
        if (s[i] == ' ')
        {
            s[i + 1] = toupper(s[i + 1]);
        }
        else if (s[i] >= 65 && s[i] <= 90 && s[i - 1] != ' ')
            s[i] = tolower(s[i]);
        i++;
    }
    return s;
}

int main()
{
    cout << solution("3people unFollowed me");
    return 0;
}