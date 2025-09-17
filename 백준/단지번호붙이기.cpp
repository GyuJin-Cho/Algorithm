#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N;
bool Visited[26][26];
int Map[26][26];
int Dy[] = {0, 1, 0, -1};
int Dx[] = {1, 0, -1, 0};
vector<int> Answer;
int Count = 0;

void DFS(int _Y, int _X)
{
    Count++;
    Visited[_Y][_X] = true;
    for (int i = 0; i < 4; i++)
    {
        int NextY = _Y + Dy[i];
        int NextX = _X + Dx[i];
        if (NextY >= 0 && NextX >= 0 && NextY < N && NextX < N)
        {
            if (!Visited[NextY][NextX] && Map[NextY][NextX] == 1)
            {
                DFS(NextY, NextX);
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            Map[i][j] = temp[j] - 48;
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Map[i][j] == 1 && !Visited[i][j])
            {
                cnt++;
                DFS(i, j);
                Answer.push_back(Count);
                Count = 0;
            }
        }
    }
    sort(Answer.begin(), Answer.end());
    cout << cnt << '\n';
    for (const int& ans : Answer)
        cout << ans << '\n';
    return 0;
}
