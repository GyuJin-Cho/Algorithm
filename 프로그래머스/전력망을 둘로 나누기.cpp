#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
int cnt;
vector<int> v[101];

void BFS(int v1, int v2)
{
    queue<int> q;
    vector<bool> visit(101);

    q.push(v1);
    visit[v1] = true;
    visit[v2] = true;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        for(int i=0;i<v[n].size();i++)
        {
            int n2 = v[n][i];

            if(visit[n2])
                continue;

            cnt++;
            q.push(n2);
            visit[n2] = true;
        }
    }
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 101;

    for(int i=0;i<wires.size();i++)
    {
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }

    
    for (auto i : wires)
    {
        cnt = 1;
        int v1 = i[0];
        int v2 = i[1];

        BFS(v1, v2);
        answer = min(answer, abs(2 * cnt - n));
    }

    return answer;
}

int main()
{
    vector<vector<int>> w = { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
    cout << solution(9, w);

    return 0;
}