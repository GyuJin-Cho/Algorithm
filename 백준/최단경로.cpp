#include <bits/stdc++.h>

using namespace std;

int V,E,K;
vector<pair<int,int>> Arr[20001];
int Dist[20001];
vector<int> Ans;
constexpr int INF=1e9;
void Dijkstra()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,K));
    Dist[K] = 0;
    while(!pq.empty())
    {
        int nownode = pq.top().second;
        int nowcost = pq.top().first;
        pq.pop();
        if(nowcost>Dist[nownode])
            continue;
        for(int i=0;i<Arr[nownode].size();i++)
        {
            int nextcost = Arr[nownode][i].second;
            int nextnode = Arr[nownode][i].first;
            if(nextcost+nowcost < Dist[nextnode])
            {
                Dist[nextnode] = nextcost + nowcost;
                pq.push(make_pair(Dist[nextnode],nextnode));
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>V>>E>>K;

    fill(Dist,Dist+20001, INF);
    
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Arr[u].push_back(make_pair(v,w));
    }

    Dijkstra();

    for(int i=1;i<=V;i++)
    {
        if(Dist[i] == INF)
            cout<<"INF"<<'\n';
        else
            cout<<Dist[i]<<'\n';
    }
    
    return 0;
}