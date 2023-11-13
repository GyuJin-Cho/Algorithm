#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int answer = 0;
    int e = problems.size() - 1;
    int mintime;
    int alpreq = -1;
    int copreq = -1;

    for(int i=0;i<=e;i++)
    {
        if (alpreq < problems[i][0])
            alpreq = problems[i][0];
        if (copreq < problems[i][1])
            copreq = problems[i][1];
    }

    if (alpreq <= alp && copreq <= cop)
        return 0;

    vector<vector<int>> dp(alpreq + 1, vector<int>(copreq + 1, INF));

    if (alp > alpreq)
        alp = alpreq;
    if (cop > copreq)
        cop = copreq;

    dp[alp][cop] = 0;

    for(int i=alp;i<=alpreq;i++)
    {
	    for(int j=cop;j<=copreq;j++)
	    {
		    if(j+1<=copreq)
		    {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
		    }
            if(i+1<=alpreq)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            for(int k=0;k<=e;k++)
            {
	            if(i>=problems[k][0]&&j>=problems[k][1])
	            {
                    dp[min(i + problems[k][2], alpreq)][min(j + problems[k][3], copreq)] = min(dp[min(i + problems[k][2], alpreq)][min(j + problems[k][3], copreq)], dp[i][j] + problems[k][4]);
	            }
            }
	    }
    }

    answer = dp[alpreq][copreq];
    return answer;
}

int main()
{
    vector<vector<int>> pro = { {10, 15, 2, 1, 2}, {20, 20, 3, 3, 4} };
    cout << solution(10, 10, pro);

    return 0;
}