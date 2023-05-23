#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n)
{
    int size = my_string.size() - n;
    string answer = "";
    for(int i=size;i<my_string.size();i++)
    {
        answer += my_string[i];
    }
    return answer;
}

int main()
{
    cout << solution("ProgrammerS123", 11);

    return 0;
}