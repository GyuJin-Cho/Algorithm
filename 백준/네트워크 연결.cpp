#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<pair<int,int>> Edge[1001];
bool Visited[1001];
int ans;

void MST()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        int NowCost = pq.top().first;
        int NowNode = pq.top().second;
        pq.pop();
        if(Visited[NowNode])
            continue;
        Visited[NowNode] = true;
        ans += NowCost;
        for(const pair<int,int>& edge : Edge[NowNode])
        {
            int NextNode = edge.first;
            int NextCost = edge.second;
            if(!Visited[NextNode])
                pq.push(make_pair(NextCost,NextNode));
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        Edge[a].push_back(make_pair(b,c));
        Edge[b].push_back(make_pair(a,c));
    }

    MST();
    cout<<ans;
    return 0;
}