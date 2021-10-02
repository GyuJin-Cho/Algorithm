#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(char a, char b)
{
    return a > b;
}

string solution(string s)
{
    string answer = "";
    vector<char> c;
    sort(s.begin(), s.end(), cmp);

    answer = s;
    return answer;
}

int main()
{
    cout << solution("Zbcdefg");
    return 0;
}