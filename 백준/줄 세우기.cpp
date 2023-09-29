#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> graph[32001];
int ind[32001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        ind[y]++;
    }
    
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout<<x<<' ';
        for(int i=0;i<graph[x].size();i++)
        {
            int y = graph[x][i];
            ind[y]--;
            if(ind[y]==0)
                q.push(y);
        }
    }
    return 0;
}
