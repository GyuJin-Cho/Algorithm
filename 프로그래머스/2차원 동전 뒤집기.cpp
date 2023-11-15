#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
constexpr int INF = 21740000;
int diff[11][11];
int N, M;
int answer = INF;
vector<int> vec;

int solved()
{
    int res = 0;
    int tmp[11][11];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            tmp[i][j] = diff[i][j];

    for (auto i : vec)
    {
        for (int j = 0; j < M; j++)
        {
            tmp[i][j] ^= 1;
        }
        res++;
    }

    for (int j = 0; j < M; j++)
    {
        if (tmp[0][j] == 1)
            res++;
        for (int i = 1; i < N; i++)
        {
            if (tmp[i][j] != tmp[0][j])
                return INF;
        }
    }
    return res;
}

void choose(int idx)
{
    if (idx == N)
    {
        answer = min(answer, solved());
        return;
    }
    vec.push_back(idx);
    choose(idx + 1);
    vec.pop_back();
    choose(idx + 1);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target)
{
    N = beginning.size();
    M = beginning[0].size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (beginning[i][j] != target[i][j])
                diff[i][j] = 1;
            else
                diff[i][j] = 0;
        }
    }

    choose(0);
    if (answer == INF)
        return -1;
    else
        return answer;
}

int main()
{
    vector<vector<int>> b = { {0, 1, 0, 0, 0}, {1, 0, 1, 0, 1},{0, 1, 1, 1, 0},{1, 0, 1, 1, 0},{0, 1, 0, 1, 0}};
    vector<vector<int>> t = { {0, 0, 0, 1, 1},{0, 0, 0, 0, 1},{0, 0, 1, 0, 1},{0, 0, 0, 1, 0},{0, 0, 0, 0, 1} };
    cout << solution(b, t);
    return 0;
}