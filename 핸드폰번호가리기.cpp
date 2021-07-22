#include <string>
#include <vector>
#include <iostream>
using namespace std;
string solution(string phone_number)
{
    string answer = "";
    int size = phone_number.length();
    for (int i = 0; i < size - 4; i++)
    {
        answer += "*";
    }
    for (int i = size - 4; i < size; i++)
    {
        answer += phone_number[i];
    }
    return answer;
}

int main()
{
    string answer = "027778888";
    cout << solution(answer);
}