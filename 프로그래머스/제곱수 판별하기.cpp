#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n)
{
    int answer = 0;
    int sq = sqrt(n);
    if (n % sq == 0)
        answer = 1;
    else
        answer = 2;

    return answer;
}

int main()
{
    cout << solution(976);

    return 0;
}