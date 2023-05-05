#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    vector<int> answer;

    for (int i = 0; i < num_list.size(); i = i + n)
    {
        answer.push_back(num_list[i]);
    }

    return answer;
}

int main()
{
    vector<int> v = { 4,2,6,1,7,6 };
    vector<int> ans = solution(v,4);
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}