#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction)
{
    vector<int> answer(numbers.size());

    if(direction == "right")
    {
        answer[0] = numbers[numbers.size() - 1];
        int cnt = 0;
        for(int i=1;i<numbers.size();i++)
        {
            answer[i] = numbers[cnt];
            cnt++;
        }
    }
    else
    {
        answer[numbers.size()-1] = numbers[0];
        int cnt = numbers.size()-1;
        for (int i = numbers.size()-2; i >= 0 ; i--)
        {
            answer[i] = numbers[cnt];
            cnt--;
        }
    }
    return answer;
}

int main()
{
    vector<int> numbers = { 4, 455, 6, 4, -1, 45, 6 };
    vector<int> a = solution(numbers, "left");
    for (auto i : a)
        cout << i << " ";
    return 0;
}