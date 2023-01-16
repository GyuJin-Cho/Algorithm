#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;

    for(int i=1;i<=n;i++)
    {
        if (i % 2 == 0)
            answer += i;
    }

    return answer;
}

int main()
{
    cout << solution(10);

    return 0;
}