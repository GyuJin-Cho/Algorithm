#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;

    for(int i=0;i<numbers.size();i++)
    {
        answer.push_back(numbers[i] * 2);
    }

    return answer;
}

int main()
{
    vector<int> num = { 1,2,3,4,5 };
    vector<int> a = solution(num);
    for (auto i : a)
        cout << i << " ";
    return 0;
}