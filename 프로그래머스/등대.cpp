#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;
constexpr int MAX = 100001;
bool Switch[MAX];

void DFS(int node, int parent, vector<vector<int>>& info)
{
    for (int i = 0; i < info[node].size(); i++)
    {
        if (info[node][i] != parent)
        {
            DFS(info[node][i], node, info);
            if (!Switch[info[node][i]] && !Switch[node])
            {
                Switch[node] = true;
                answer++;
            }
        }

    }
}

int solution(int n, vector<vector<int>> lighthouse)
{
    vector<vector<int>> info(n + 1);
    for (int i = 0; i < lighthouse.size(); i++)
    {
        info[lighthouse[i][0]].push_back(lighthouse[i][1]);
        info[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    DFS(1, 1, info);
    return answer;
}

int main()
{
    vector<vector<int>> v = { {1, 2},{1, 3},{1, 4},{1, 5},{5, 6}, {5, 7},{5, 8}};
    cout << solution(8, v);

    return 0;
}