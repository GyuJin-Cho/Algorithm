#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<string.h>
using namespace std;

struct node
{
    int y;
    int x;
};

int Map[1001][1001];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int N,M;
int visited[1001][1001] = {0};
void BFS(int y,int x)
{
    queue<node> q;
    q.push({y,x});
    
    visited[y][x] = 1;
    
    while(!q.empty())
    {
        node n = q.front();
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = dy[i] + n.y;
            int nx = dx[i] + n.x;
            
            if(ny>=0&&nx>=0&&ny<N&&nx<M)
            {
                if(visited[ny][nx]==0&&(Map[ny][nx]==1||Map[ny][nx]==2))
                {
                    visited[ny][nx] = visited[n.y][n.x]+1;
                    q.push({ny,nx});
                }
            }
        }
        
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    int Y,X;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            cin>>Map[i][j];
            if(Map[i][j]==2)
            {
                Y=i;
                X=j;
            }
        }
            
    BFS(Y,X);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(Map[i][j]==0)
                cout<<0<<' ';
            else
                cout<<visited[i][j]-1<<' ';  
        }
        cout<<'\n';
    }
        
    
    return 0;
}
