#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
#include <cctype>
using namespace std;

string solution(string my_string)
{
    string answer = "";
    
    for(int i=0;i<my_string.size();i++)
    {
        answer += tolower(my_string[i]);
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    cout << solution("Bcad");

    return 0;
}