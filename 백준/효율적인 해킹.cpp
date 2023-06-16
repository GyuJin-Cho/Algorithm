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
#include<memory.h>

using namespace std;
vector<vector<int>> computers(100001);
int MaxCnt;
int cnt=-1;
bool visit[100001];
void InitVisit()
{
    memset(visit, false, sizeof(visit));
}

void DFS(int L)
{
    visit[L] = true;
    cnt++;
    for(int i=0;i<computers[L].size();i++)
    {
        if (!visit[computers[L][i]])
            DFS(computers[L][i]);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    int a, b;
    vector<int> ans;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        computers[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
    {
        cnt = -1;
        DFS(i);
        InitVisit();
        if (cnt > MaxCnt)
        {
            ans.clear();
            ans.push_back(i);
            MaxCnt = cnt;
        }
        else if (cnt == MaxCnt)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << ' ';

    return 0;
}