#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(const vector<int>& numbers, int idx, int target,int sum)
{
    if (numbers.size() == idx)
    {
        if (target == sum)
            answer++;
        return;
    }
    DFS(numbers, idx + 1, target, sum + numbers[idx]);
    DFS(numbers, idx + 1, target, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target)
{
    DFS(numbers, 0, target,0);
    return answer;
}

int main()
{
    vector<int> v = { 4,1,2,1 };
    cout << solution(v, 4);

    return 0;
}