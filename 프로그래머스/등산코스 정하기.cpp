#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> edge[50001];
int dist[50001];
bool summit[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
vector<int> v;
int Dijkstra()
{
	while(!pq.empty())
	{
        int nownode = pq.top().second;
        int nowcost = pq.top().first;
        pq.pop();
        if(dist[nownode]!=nowcost)
            continue;
        for(int i=0;i<edge[nownode].size();i++)
        {
	        if(dist[edge[nownode][i].first]<=max(dist[nownode],edge[nownode][i].second))
	        {
		        continue;
	        }
            dist[edge[nownode][i].first] = max(dist[nownode], edge[nownode][i].second);
            if(!summit[edge[nownode][i].first])
            {
                pq.push({ dist[edge[nownode][i].first],edge[nownode][i].first });
            }
        }
	}
    int ans = summit[0];
    for(auto i : v)
    {
	    if(dist[i]<dist[ans])
	    {
            ans = i;
	    }
        else if(dist[i]==dist[ans]&&i<ans)
        {
            ans = i;
        }
    }
    return ans;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<int> answer;
    for (auto i : summits)
        summit[i] = true;
    v = summits;
    for(int i=0;i<paths.size();i++)
    {
        edge[paths[i][0]].push_back(make_pair(paths[i][1], paths[i][2]));
        edge[paths[i][1]].push_back(make_pair(paths[i][0], paths[i][2]));
    }
    for(int i=0;i<50001;i++)
    {
        dist[i] = 21740000;
    }
    for(int i=0;i<gates.size();i++)
    {
        dist[gates[i]] = 0;
        pq.push({ 0,gates[i] });
    }

    int ans = Dijkstra();
    answer.push_back(ans);
    answer.push_back(dist[ans]);
    return answer;
}

int main()
{
    vector<vector<int>> paths = { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} };
    vector<int> v = solution(6, paths, { 1,3 }, { 5 });
    for (auto i : v)
        cout << i << ' ';
    return 0;
}