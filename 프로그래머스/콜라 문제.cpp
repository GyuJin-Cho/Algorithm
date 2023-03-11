#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;

    while(n>=a)
    {
        int Ret = (n / a) * b;
        answer += Ret;
        n = n - (n/a*a) + Ret;

    }

    return answer;
}

int main()
{
    cout << solution(3, 1, 20);

    return 0;
}