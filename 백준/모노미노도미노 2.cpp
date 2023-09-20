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
int simulate(vector<vector<int>>& board, int col, int type)
{
    int ans = 0;
    int max_row = -1;
    for (int i = 0; i < board.size(); i++) 
    {
        if (board[i][col] == 0) 
        {
            max_row = i;
        }
        else 
        {
            break;
        }
    }
    if (type == 2) 
    {
        int max_row_2 = -1;
        for (int i = 0; i < board.size(); i++) 
        {
            if (board[i][col + 1] == 0) 
            {
                max_row_2 = i;
            }
            else 
            {
                break;
            }
        }
        max_row = min(max_row, max_row_2);
    }
    board[max_row][col] = 1;
    if (type == 2)
        board[max_row][col + 1] = 1;
    if (type == 3) 
        board[max_row - 1][col] = 1;
    int deleted_row = -1;
    for (int i = 0; i < board.size(); i++) 
    {
        bool all = true;
        for (int j = 0; j < board[i].size(); j++) 
        {
            if (board[i][j] == 0) 
            {
                all = false;
            }
        }
        if (all) 
        {
            if (deleted_row < i) 
            {
                deleted_row = i;
            }
            ans += 1;
            for (int j = 0; j < board[i].size(); j++) 
            {
                board[i][j] = 0;
            }
        }
    }
    if (ans > 0) 
    {
        for (int i = deleted_row; i >= 0; i--) 
        {
            for (int j = 0; j < board[i].size(); j++) 
            {
                board[i][j] = 0;
                if (i - ans >= 0) 
                {
                    board[i][j] = board[i - ans][j];
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 2; i++) 
    {
        bool exists = false;
        for (int j = 0; j < board[i].size(); j++) 
        {
            if (board[i][j] != 0) 
            {
                exists = true;
            }
        }
        if (exists) cnt += 1;
    }
    if (cnt > 0) 
    {
        int bn = board.size();
        for (int i = bn - 1; i >= 0; i--) 
        {
            for (int j = 0; j < board[i].size(); j++) 
            {
                board[i][j] = 0;
                if (i - cnt >= 0) 
                {
                    board[i][j] = board[i - cnt][j];
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<int>> green(6, vector<int>(4));
    vector<vector<int>> blue(6, vector<int>(4));
    while (n--) 
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) 
        {
            ans += simulate(green, y, 1);
        }
        else if (t == 2) 
        {
            ans += simulate(green, y, 2);
        }
        else if (t == 3) 
        {
            ans += simulate(green, y, 3);
        }
        if (t == 1) 
        {
            ans += simulate(blue, x, 1);
        }
        else if (t == 2) 
        {
            ans += simulate(blue, x, 3);
        }
        else if (t == 3) 
        {
            ans += simulate(blue, x, 2);
        }
    }
    cout << ans<<'\n';
    int cnt = 0;
    for (int i = 0; i < green.size(); i++) 
    {
        for (int j = 0; j < green[i].size(); j++) 
        {
            if (green[i][j] > 0) cnt += 1;
        }
    }
    for (int i = 0; i < blue.size(); i++) 
    {
        for (int j = 0; j < blue[i].size(); j++) 
        {
            if (blue[i][j] > 0) cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}
