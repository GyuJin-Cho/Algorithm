#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string my_string)
{
    string answer = "";
    reverse(my_string.begin(), my_string.end());
    answer = my_string;
    return answer;
}

int main()
{
    cout << solution("jaron");

    return 0;
}