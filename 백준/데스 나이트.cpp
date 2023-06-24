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

using namespace std;

int N;
int r1,c1,r2,c2;
bool vi[201][201];
int dy[] = {-2,-2,0,0,2,2};
int dx[] = {-1,1,-2,2,-1,1};
struct node
{
    int y;
    int x;
    int cnt;
};

void BFS()
{
    queue<node> q;
    q.push({r1,c1,0});
    vi[r1][c1] = true;
    while(!q.empty())
    {
        node n = q.front();
        q.pop();
        if(n.y==r2&&n.x==c2)
        {
            cout<<n.cnt;
            return;
        }
        
        for(int i=0;i<6;i++)
        {
            int ny = dy[i] + n.y;
            int nx = dx[i] + n.x;
            if(ny>=0&&nx>=0&&ny<N&&nx<N)
            {
                if(!vi[ny][nx])
                {
                    q.push({ny,nx,n.cnt+1});
                    vi[ny][nx] = true;
                }
            }
        }
    }
    cout<<-1;
}

int main()
{
    cin>>N;
    cin>>r1>>c1>>r2>>c2;
    BFS();
    
    return 0;
}
