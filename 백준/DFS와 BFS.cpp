#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int N,M,V;
int map[1001][1001];
bool visited[1001] = {false};

void InitVisted()
{
    memset(visited,false,sizeof(visited));
}

void DFS(int v)
{
    cout<<v<<' ';
    visited[v]=true;
    for(int i=1;i<=N;i++)
    {
        if(!visited[i] && map[v][i] == 1)
        {
            DFS(i);
        }
    }
}

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    visited[v]=true;
    while(!q.empty())
    {
        int u = q.front();
        cout<<u<<' ';
        q.pop();
        for(int i=1;i<=N;i++)
        {
            if(!visited[i] && map[u][i] == 1)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    cin>>N>>M>>V;
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        map[u][v] = map[v][u] = 1;
    }

    DFS(V);
    cout<<'\n';
    InitVisted();
    BFS(V);
    
    return 0;
}