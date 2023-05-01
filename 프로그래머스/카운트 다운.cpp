#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start, int end)
{
    vector<int> answer;

    for(int i=start;i>=end;i--)
    {
        answer.push_back(i);
    }

    return answer;
}

int main()
{

    vector<int> v = solution(10, 3);
    for(auto i : v)
    {
        cout << i << ' ';
    }
    return 0;
}