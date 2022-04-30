#include<iostream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> V[51];
vector<int>Dist;
vector<int> qqq[100];
void Dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0,1));
    Dist[1] = 0;
    
    while (!pq.empty())
    {
        int Cost = -pq.top().first;
        int Cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < V[Cur].size(); i++)
        {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;

            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                pq.push(make_pair(-Dist[Next], Next));
            }
        }
    }

}

int solution(int N, vector<vector<int>> road, int K) 
{
    int answer = 0;
    Dist.resize(N + 1, 9999999);

    for (int i = 0; i < road.size(); i++)
    {
        int N1 = road[i][0];
        int N2 = road[i][1];
        int Dist = road[i][2];

        V[N1].push_back(make_pair(N2, Dist));
        V[N2].push_back(make_pair(N1, Dist));
    }

    Dijkstra();

    for (int i = 1; i <= N; i++)
    {
        if (Dist[i] <= K)
            answer++;
    }

    return answer;
}

int main()
{
    vector<vector<int>> v = { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} };
    cout << solution(5, v, 3);

    return 0;
}