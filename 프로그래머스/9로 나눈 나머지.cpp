#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string number)
{
    int answer = 0;
    for(int i=0;i<number.size();i++)
    {
        answer = answer + (number[i] - 48);
    }
    answer %= 9;
    return answer;
}

int main()
{
    cout << solution("78720646226947352489");

    return 0;
}