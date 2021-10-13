#include <string>
#include <vector>
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> m;
    int index;
    string temp = "";
    
    for (index = 1; index < 27; index++)
    {
        temp = 'A' + index-1;
        m.insert({ temp,index });
        temp = "";
    }

    for (int i = 0; i < msg.length(); i++)
    {
        temp = "";
        temp += msg[i];
        int j = i;
        int count = 0;

        while (m.find(temp) != m.end())
        {
            count++;
            j++;
            temp += msg[j];
        }

        i += count - 1;
        m.insert({ temp,index++ });
        temp.pop_back();
        answer.emplace_back(m[temp]);
    }

    return answer;
}

int main()
{
    vector<int> a = solution("KAKAO");
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}