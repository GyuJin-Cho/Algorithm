#include<iostream>
#include<queue>
#include<array>
using namespace std;

int N,M;

vector<vector<int>> Map;
vector<vector<bool>> Visited;
vector<vector<int>> ArrCnt;
array<int,4> Dy = {0,1,0,-1};
array<int,4> Dx = {1,0,-1,0};
constexpr int Cicle = 4;
void BFS()
{
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    Visited[0][0] = true;
    ArrCnt[0][0] = 1;
    while(!q.empty())
    {
        int NowY = q.front().first;
        int NowX = q.front().second;
        q.pop();
        if(NowY == N-1 && NowX == M-1)
        {
            cout<<ArrCnt[NowY][NowX];
            return;
        }
        for(int i=0;i<Cicle;i++)
        {
            int NextY = NowY + Dy[i];
            int NextX = NowX + Dx[i];
            if(NextX >= 0 && NextY >=0 && NextX < M && NextY < N)
            {
                if(!Visited[NextY][NextX] && Map[NextY][NextX] == 1)
                {
                    q.push(make_pair(NextY,NextX));
                    Visited[NextY][NextX] = true;
                    ArrCnt[NextY][NextX] = ArrCnt[NowY][NowX] + 1;
                }
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
    Map.resize(N + 1);
    Visited.resize(N + 1);
    ArrCnt.resize(N + 1);
    for(int i=0;i<N;i++)
    {
        Map[i].resize(M + 1);
        Visited[i].resize(M + 1);
        ArrCnt[i].resize(M + 1);
        string temp;
        cin>>temp;
        for(size_t j=0;j<temp.length();j++)
        {
            Map[i][j] = temp[j] - 48;
        }
    }

    BFS();
    
    return 0;
}