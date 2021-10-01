#include<iostream>
#include<cmath>
#include<string>
using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    long long a = sqrtl(n);
    if(a*a==n)
    {
        answer = (a + 1) * (a + 1);
    }
    else
    {
        answer = -1;
    }
    string s = to_string(a);
    return answer;
}

int main()
{
    cout << solution(50000000000000);
    return 0;
}