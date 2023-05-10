#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString)
{
    vector<int> answer;
    string tmp = "";
    vector<string> v;
    for (int i = 0; i < myString.size(); i++)
    {
        if (myString[i] == 'x')
        {
            v.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp += myString[i];
        }
    }
    
    for(int i=0;i<v.size();i++)
    {
        answer.push_back(v[i].size());
    }
    if (myString[myString.size() - 1] == 'x')
        answer.push_back(0);
    else if (!tmp.empty())
        answer.push_back(tmp.size());
    return answer;
}

int main()
{
    vector<int> ans = solution("xabcxdefxghi");
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}