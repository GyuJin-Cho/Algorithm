#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dp[2001];
constexpr long long MOD = 1234567;
long long solution(int n)
{
    long long answer = 0;

    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2])%MOD;
    }
    answer = dp[n];
    return answer;
}

int main()
{
    cout << solution(5);

    return 0;
}