#define _CRT_SECURE_NO_WARNINGS 
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

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int r = board.size();
    int c = board[0].size();
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (board[i][j] != 0)
            {
                board[i][j] = 1 + min({ board[i - 1][j - 1],board[i - 1][j],board[i][j - 1] });
                answer = max(answer, board[i][j]);
            }
        }
    }

    answer = answer* answer;
    return answer;
}

int main()
{
	int n, m;
    cin >> n >> m;
   
	vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &v[i][j]);
    cout << solution(v);
	return 0;
}