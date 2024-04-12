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
#include<cstring>

using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M;

    vector<string> Castle(N);
    vector<bool> HasGuardInRow(N, false);
    vector<bool> HasGuardInCol(M, false);

    for (int i = 0; i < N; i++)
    {
        cin >> Castle[i];
        for (int j = 0; j < M; j++) 
        {
            if (Castle[i][j] == 'X') 
            {
                HasGuardInRow[i] = true;
                HasGuardInCol[j] = true;
            }
        }
    }

    int RowsWithoutGuard = 0;
    int ColsWithoutGuard = 0;

    for (int i = 0; i < N; i++) 
    {
        if (!HasGuardInRow[i]) 
            RowsWithoutGuard++;
    }

    for (int j = 0; j < M; j++) 
    {
        if (!HasGuardInCol[j])
            ColsWithoutGuard++;
    }

    cout << max(RowsWithoutGuard, ColsWithoutGuard) << endl;

    return 0;
}