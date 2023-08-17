#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>

using namespace std;
long long D[91];
int main()
{
    int n;
    cin >> n;
    D[1] = 1;
    D[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        D[i] = D[i - 1] + D[i - 2];
    }
    cout << D[n];
    return 0;
}