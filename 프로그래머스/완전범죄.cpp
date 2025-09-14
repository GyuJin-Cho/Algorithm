#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    const int INF = 1e9;
    int items = info.size();
    vector<int> dp(m, INF);
    dp[0] = 0;

    for (int i = 0; i < items; ++i)
    {
        vector<int> ndp(m, INF);
        int a_cost = info[i][0];
        int b_cost = info[i][1];

        for (int b = 0; b < m; ++b)
        {
            if (dp[b] == INF)
                continue;
            int curA = dp[b];

            int newA = curA + a_cost;
            if (newA < n)
            { 
                ndp[b] = min(ndp[b], newA);
            }

            int newB = b + b_cost;
            if (newB < m)
            { 
                ndp[newB] = min(ndp[newB], curA);
            }
        }
        dp.swap(ndp);
    }

    int ans = INF;
    for (int b = 0; b < m; ++b)
    {
        if (dp[b] < INF) ans = min(ans, dp[b]);
    }
    if (ans == INF)
        return -1;
    return ans;
}

int main()
{
    vector<vector<int>> info1 = {{1,2},{2,3},{2,1}};
    cout << solution(info1, 4, 4) << " (expect 2)\n";

    vector<vector<int>> info2 = {{1,2},{2,3},{2,1}};
    cout << solution(info2, 1, 7) << " (expect 0)\n";

    vector<vector<int>> info3 = {{3,3},{3,3}};
    cout << solution(info3, 7, 1) << " (expect 6)\n";

    vector<vector<int>> info4 = {{3,3},{3,3}};
    cout << solution(info4, 6, 1) << " (expect -1)\n";

    return 0;
}
