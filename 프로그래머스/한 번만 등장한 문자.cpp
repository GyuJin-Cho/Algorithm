#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string solution(string s)
{
    string answer = "";
    map<char, int> m;
    for(int i=0;i<s.size();i++)
    {
        m[s[i]]++;
    }

    for(auto i : m)
    {
        if (i.second == 1)
            answer += i.first;
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    cout << solution("abcabcadc");

    return 0;
}