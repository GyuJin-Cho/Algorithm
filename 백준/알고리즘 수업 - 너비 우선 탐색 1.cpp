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

using namespace std;
vector<int> graph[100001];
bool visited[100001] = {false};
int result[100001] = {0};
int cnt = 0;

void BFS(int R)
{
    queue<int> q;
    q.push(R);
    visited[R] = true;
    cnt++;
    result[R] = cnt;
    
    while(!q.empty())
    {
        int nextlevel = q.front();
        q.pop();
        for(int i=0;i<graph[nextlevel].size();i++)
        {
            int tmp = graph[nextlevel][i];
            if(!visited[tmp])
            {
                cnt++;
                result[tmp] = cnt;
                q.push(tmp);
                visited[tmp] = true;
            }
        }
    }
    
}

int main()
{
    int n,m,r;
    cin>>n>>m>>r;
    
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    
    BFS(r);
    
    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << '\n';
    }
    
    return 0;
}
