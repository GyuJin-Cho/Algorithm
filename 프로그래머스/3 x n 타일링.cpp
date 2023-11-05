#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long DP[5010];
#define MOD 1000000007
int solution(int n)
{
    if (n % 2 == 1)
        return 0;
    DP[0] = 1;
    DP[2] = 3;
    for (int i = 4; i <= n; i = i + 2)
    {
        DP[i] = DP[i - 2] * 3;
        for (int j = i - 4; j >= 0; j = j - 2)
        {
            DP[i] = DP[i] + DP[j] * 2;
        }
        DP[i] = DP[i] % MOD;
    }

    return (int)DP[n];
}

int main()
{
    cout << solution(4);

    return 0;
}