#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total)
{
    vector<int> answer(num);

    int Sum = num * (1 + num) / 2;
    int start = (total - Sum) / num;

    for(int i=1;i<num+1;i++)
    {
        answer[i - 1] = i + start;
    }

    return answer;
}

int main()
{
    vector<int> a = solution(3, 12);

    for(auto i : a)
    {
        cout << i << " ";
    }

    return 0;
}