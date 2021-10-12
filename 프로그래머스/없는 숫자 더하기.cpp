#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool visit[10] = { false, };
int solution(vector<int> numbers)
{
    int answer = 0;
    vector<int> num;
    for (int i = 0; i < numbers.size(); i++)
    {
        visit[numbers[i]] = true;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!visit[i])
        {
            num.push_back(i);
        }
    }

    for (int i = 0; i < num.size(); i++)
    {
        answer += num[i];
    }
    return answer;
}

int main()
{
    vector<int> a = { 5,8,4,0,6,7,9 };
    cout << solution(a);
    return 0;
}