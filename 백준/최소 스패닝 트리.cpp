#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N,M;
vector<pair<long long,long long>> Edge[10001];
bool Visited[10001];
long long ans = 0;

void MST()
{
    priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>>> pq;

    pq.push({0,1});
    while(!pq.empty())
    {
        long long NowNode = pq.top().second;
        long long NowCost = pq.top().first;
        pq.pop();
        if(Visited[NowNode])
            continue;
        Visited[NowNode] = true;
        ans += NowCost;
        for(int i=0; i<Edge[NowNode].size();i++)
        {
            int nCost = Edge[NowNode][i].second;
            int nNode = Edge[NowNode][i].first;
            if(!Visited[nNode])
            {
                pq.push({nCost,nNode});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        long long u,v,c;
        cin>>u>>v>>c;
        Edge[u].push_back(make_pair(v,c));
        Edge[v].push_back(make_pair(u,c));
    }

    MST();
    
    cout<<ans;
    return 0;
}