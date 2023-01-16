#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2)
{
    vector<int> answer;
    for(int i=num1;i<=num2;i++)
    {
        answer.push_back(numbers[i]);
    }
    return answer;
}

int main()
{
    vector<int> numbers = { 1,3,5 };
    vector<int> a = solution(numbers, 1, 2);
    for (auto i : a)
        cout << i << " ";

    return 0;
}