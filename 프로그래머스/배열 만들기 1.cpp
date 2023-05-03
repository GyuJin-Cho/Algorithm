#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k)
{
    vector<int> answer;

    for(int i=k;i<=n;i=i+k)
    {
        answer.push_back(i);
    }

    return answer;
}

int main()
{
    vector<int> ans = solution(15, 5);
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}