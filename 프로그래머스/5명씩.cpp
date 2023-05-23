#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names)
{
    vector<string> answer;

    for (int i = 0; i < names.size(); i = i + 5)
    {
        answer.push_back(names[i]);
    }

    return answer;
}

int main()
{
    vector<string> v = { "nami", "ahri", "jayce", "garen", "ivern", "vex", "jinx" };
    vector<string> ans = solution(v);
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}