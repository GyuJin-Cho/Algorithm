#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string message)
{
    int answer = message.size()*2;

    return answer;
}

int main()
{
    cout << solution("happy birthday!");

    return 0;
}