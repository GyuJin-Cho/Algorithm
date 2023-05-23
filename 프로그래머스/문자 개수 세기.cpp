#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string my_string)
{
    vector<int> answer;

    map<char, int> m;
    for(int i=0;i<my_string.size();i++)
    {
        m[my_string[i]]++;
    }

    for(char ch= 'A';ch<='Z';ch++)
    {
        answer.push_back(m[ch]);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        answer.push_back(m[ch]);
    }

    return answer;
}

int main()
{
    vector<int> ans = solution("Programmers");

    for(int i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}