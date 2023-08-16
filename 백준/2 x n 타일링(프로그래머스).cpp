#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long D[60001];
int solution(int n)
{
    D[0] = 0;
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        D[i] = D[i - 2] + D[i - 1];
        D[i] %= 1000000007;
    }
    return D[n];
}

int main()
{
    cout << solution(4);
}