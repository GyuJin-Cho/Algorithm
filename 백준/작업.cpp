#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

vector<int> graph[10001];
int ind[10001];
int work[10001];
int d[10001];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>work[i];
        int cnt;
        cin>>cnt;
        for(int j=0;j<cnt;j++)
        {
            int x;
            cin>>x;
            graph[x].push_back(i);
            ind[i]++;
        }
    }
    
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
            d[i] = work[i];
        }
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++)
        {
            int y = graph[x][i];
            ind[y]--;
            if(d[y]<d[x]+work[y])
            {
                d[y] = d[x]+work[y];
            }
            if(ind[y]==0)
                q.push(y);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(ans<d[i])
            ans=d[i];
    }
    cout<<ans;
    return 0;
}
