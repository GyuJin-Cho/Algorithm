#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    int answer = 0;
    string s1;
    string s2;
    for(int i=0;i<myString.size();i++)
    {
       s1 += tolower(myString[i]);
    }
    for (int i = 0; i < pat.size(); i++)
    {
        s2 += tolower(pat[i]);
    }
    if(s1.find(s2)==string::npos)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return answer;
}

int main()
{
    cout << solution("aaAA", "aaaaa");

    return 0;
}