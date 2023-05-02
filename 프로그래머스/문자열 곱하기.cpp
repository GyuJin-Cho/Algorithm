#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int k)
{
    string answer = "";
    for(int i=0;i<k;i++)
    {
        answer += my_string;
    }

    return answer;
}

int main()
{
    cout << solution("string", 3);

    return 0;
}