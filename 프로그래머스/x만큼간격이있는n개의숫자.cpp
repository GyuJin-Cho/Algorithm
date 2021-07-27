#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<long long> solution(int x, int n)
{
    vector<long long> answer;
    for (int i = 1; i <= n; i++)
    {
        answer.push_back(x * i);
    }
    return answer;
}

int main()
{
    vector<long long> answer = solution(-4,2);
    
    for (auto i : answer)
    {
        cout << i << " ";
    }
}