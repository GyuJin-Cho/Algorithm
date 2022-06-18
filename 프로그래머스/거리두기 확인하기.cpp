#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> answer;
struct node
{
    int y;
    int x;
    int cnt;
};
bool visit[6][6] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool check = true;
void visitInit()
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            visit[i][j] = false;
}

void BFS(int y, int x, vector<vector<char>> places)
{
    queue<node> q;
    q.push({ y,x,0 });
    visit[y][x] = true;

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int ncnt = q.front().cnt;
        q.pop();

        if (ncnt == 2)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny > -1 && nx > -1 && ny < 5 && nx < 5)
            {
                if (!visit[ny][nx])
                {
                    if (places[ny][nx] == 'O')
                    {
                        visit[ny][nx] = true;
                        q.push({ ny, nx, ncnt + 1 });
                    }
                    else if (places[ny][nx] == 'P')
                    {
                        check = false;
                        return;
                    }
                }
            }
        }
    }
    check = true;
}

vector<int> solution(vector<vector<string>> places)
{
    for (int i = 0; i < places.size(); i++)
    {
        vector<vector<char>> pl;
        check = true;
        visitInit();
        for (int j = 0; j < places[i].size(); j++)
        {
            vector<char> temp;
            for (int z = 0; z < places[i][j].size(); z++)
            {
                char a = places[i][j][z];
                temp.push_back(a);
            }
            pl.push_back(temp);
        }
        for (int j = 0; j < pl.size(); j++)
        {
            for (int z = 0; z < pl[j].size(); z++)
            {
                if (pl[j][z] == 'P')
                {
                    BFS(j, z, pl);
                    if (!check)
                    {
                        answer.push_back(0);
                        break;
                    }
                }
            }
            if (!check)
                break;
        }
        if (check)
            answer.push_back(1);
        
    }
    return answer;
}

int main()
{
    vector<vector<string>> places =
    {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    vector<int> ans = solution(places);

    for (auto i : ans)
        cout << i << endl;
    return 0;
}