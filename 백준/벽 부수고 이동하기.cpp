#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N,M;
bool visited[1001][1001][2];
int arr[1001][1001];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
struct Node
{
    int y;
    int x;
    bool Crash;
    int cnt;
};

void BFS()
{
    queue<Node> q;
    q.push({0,0,false,1});
    visited[0][0][0] = true;
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if(temp.y + 1 == N && temp.x + 1 == M)
        {
            cout<<temp.cnt;
            return;
        }
        for(int i=0;i<4;i++)
        {
            int ny = temp.y + dy[i];
            int nx = temp.x + dx[i];

            if(ny>=0 && nx >= 0 && ny < N && nx < M)
            {
                if(!visited[ny][nx][1] && arr[ny][nx] == 1 && !temp.Crash)
                {
                    q.push({ny,nx,true,temp.cnt+1});
                    visited[ny][nx][1] = true;
                }
                else if(!visited[ny][nx][temp.Crash] && arr[ny][nx] == 0)
                {
                    q.push({ny,nx,temp.Crash,temp.cnt+1});
                    visited[ny][nx][temp.Crash] = true;
                }
            }
        }
    }
    cout<<-1;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    string s;
    for(int i=0;i<N;i++)
    {
        cin>>s;
        for(int j = 0; j < s.length() ; j++)
        {
            arr[i][j] = s[j]-48;
        }
    }

    BFS();
    
    return 0;
}
