#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    vector<int> answer;

    sort(num_list.begin(), num_list.end());
    for(int i=5;i<num_list.size();i++)
    {
        answer.push_back(num_list[i]);
    }

    return answer;
}

int main()
{
    vector<int> v = { 12, 4, 15, 46, 38, 1, 14, 56, 32, 10 };
    vector<int> ans = solution(v);
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}