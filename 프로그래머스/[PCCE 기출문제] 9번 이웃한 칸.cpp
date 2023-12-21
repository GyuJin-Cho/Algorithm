#include <iostream>
#include <string>
#include <vector>

using namespace std;
int dh[] = { -1,0,1,0 };
int dw[] = { 0,1,0,-1 };

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    for (int i = 0; i < 4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];

        if (nh < 0 || nw < 0 || nh >= board.size() || nw >= board[0].size())
            continue;
        if (board[nh][nw] == board[h][w])
            answer++;
    }
    return answer;
}

int main()
{
    vector<vector<string>> b = { {"blue", "red", "orange", "red"},{"red", "red", "blue", "orange"},{"blue", "orange", "red", "red"},{"orange", "orange", "red", "blue"} };
    cout << solution(b, 1, 1);
    return 0;
}