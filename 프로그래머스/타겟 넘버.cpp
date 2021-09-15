#include <algorithm>
#include<iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> number,int target,int sum, int index)
{
	if(number.size()==index)
	{
        if (sum == target)
            answer++;
        return;
	}
    dfs(number, target, sum + number[index], index+1);
    dfs(number, target, sum - number[index], index+1);
}
int solution(vector<int> numbers, int target)
{
    dfs(numbers, target, 0, 0);
    return answer;
}

int main()
{
    vector<int> a = { 1,1,1,1,1 };
    int target = 3;
    cout << solution(a, target);
    return 0;
}