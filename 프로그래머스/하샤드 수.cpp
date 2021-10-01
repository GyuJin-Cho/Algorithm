#include <string>
#include <vector>
#include<iostream>

using namespace std;

bool solution(int x)
{
    bool answer = true;
    string a = to_string(x);
    int sum = 0;
    for(int i=0;i<a.length();i++)
    {
        sum += a[i] - '0';
    }
    if(x%sum==0)
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
    return answer;
}

int main()
{
    cout << solution(13);
    return 0;
}