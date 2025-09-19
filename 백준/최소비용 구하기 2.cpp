#include<bits/stdc++.h>

using namespace std;

constexpr int INF = 100000001;
int N,M,S,E;
vector<pair<int,int>> Edge[1001];
int Dist[1001];
int HistoryCity[1001];

void Dijkstra()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,S));
    Dist[S] = 0;
    while(!pq.empty())
    {
        int nowcost = pq.top().first;
        int nownode = pq.top().second;
        pq.pop();

        if(nowcost > Dist[nownode])
            continue;

        for(int i=0;i<Edge[nownode].size();i++)
        {
            int nextnode = Edge[nownode][i].first;
            int nextcost = Edge[nownode][i].second;

            if(nextcost + nowcost < Dist[nextnode])
            {
                Dist[nextnode] = nextcost + nowcost;
                pq.push(make_pair(Dist[nextnode], nextnode));
                HistoryCity[nextnode] = nownode;
            }
        }
    }
}

int main()
{
    cin>>N>>M;
    fill(Dist,Dist+N+1,INF);

    for(int i=0;i<M;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Edge[u].push_back(make_pair(v,w));
    }

    cin>>S>>E;

    Dijkstra();

    cout<<Dist[E]<<'\n';

    vector<int> history;
    history.push_back(E);
    int val = HistoryCity[E];
    while(val != 0)
    {
        history.push_back(val);
        val = HistoryCity[val];
    }

    cout<<history.size()<<'\n';
    for(int i=history.size() - 1 ; i>=0;i--)
        cout<<history[i]<<' ';
    
    return 0;
}