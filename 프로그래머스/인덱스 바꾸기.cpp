#include<iostream>
#include <string>
#include <vector>

using namespace std;
char arry[101];

string solution(string my_string, int num1, int num2)
{
    string answer = "";


    for(int i=0;i<my_string.size();i++)
    {
        arry[i] = my_string[i];
    }

    char temp;

    temp = arry[num1];
    arry[num1] = arry[num2];
    arry[num2] = temp;

    for(int i=0;i<my_string.size();i++)
    {
        answer += arry[i];
    }

    return answer;
}

int main()
{
    cout << solution("Hello", 1, 2);

    return 0;
}