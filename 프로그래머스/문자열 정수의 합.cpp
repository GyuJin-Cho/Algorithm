#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string num_str)
{
    int answer = 0;

    for(int i=0;i<num_str.size();i++)
    {
        answer += num_str[i] - 48;
    }

    return answer;
}

int main()
{
    cout << solution("123456789");

    return 0;
}