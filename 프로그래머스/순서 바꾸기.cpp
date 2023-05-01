#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n)
{
    vector<int> answer;

    for(int i=n;i<num_list.size();i++)
    {
        answer.push_back(num_list[i]);
    }
    for(int i=0;i<n;i++)
    {
        answer.push_back(num_list[i]);
    }


    return answer;
}

int main()
{
    vector<int> v = { 5, 2, 1, 7, 5 };
    vector<int> answer = solution(v, 3);
    for (auto i : answer)
    {
        cout << i << ' ';
    }

    return 0;
}