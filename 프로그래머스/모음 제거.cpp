#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string my_string)
{
    string answer = "";

    for(int i=0;i<my_string.size();i++)
    {
        if (my_string[i] == 'a' || my_string[i] == 'i' || my_string[i] == 'u' || my_string[i] == 'e' || my_string[i] == 'o')
            continue;
        answer += my_string[i];
    }


    return answer;
}

int main()
{
    cout << solution("bus");

    return 0;
}