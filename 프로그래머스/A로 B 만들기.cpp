#include<iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

int solution(string before, string after)
{
    int answer = 1;

    sort(before.begin(), before.end());
    sort(after.begin(), after.end());

    if (before != after)
        return 0;

    return answer;
}

int main()
{
    cout << solution("olleh", "hello");

    return 0;
}