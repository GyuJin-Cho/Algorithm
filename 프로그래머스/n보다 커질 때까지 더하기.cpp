#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n)
{
    int answer = 0;
    for(int i=0;i<numbers.size();i++)
    {
        answer += numbers[i];
        if(answer>n)
        {
            return answer;
        }
    }
    return answer;
}

int main()
{
    vector<int> v={ 58, 44, 27, 10, 100 };
    cout << solution(v,139);

    return 0;
}