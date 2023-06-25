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

class node
{
public:
    int y;
    int x;
    
    node(int y, int x) : y(y),x(x){}
    node() : y(0),x(0){}
};

int Map[65][65];
bool visited[65][65];
int N;
int dy[] = {0,1};
int dx[] = {1,0};
void BFS()
{
    queue<node> q;
    q.push(node());
    visited[0][0] = true;
    
    while (!q.empty())
    {
        node n = q.front();
        q.pop();
        if(Map[n.y][n.x]==-1)
        {
            cout<<"HaruHaru";
            return;
        }
        
        for(int i=0;i<2;i++)
        {
            int ny = (dy[i]*Map[n.y][n.x]) + n.y;
            int nx = (dx[i]*Map[n.y][n.x]) + n.x;
            if(ny>=0&&nx>=0&&ny<N&&nx<N)
            {
                if(!visited[ny][nx])
                {
                    q.push(node(ny,nx));
                    visited[ny][nx] = true;
                }
            }
        }
        
    }
    cout<<"Hing";
}

int main()
{
    
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0l;j<N;j++)
            cin>>Map[i][j];
    
    BFS();
    
    return 0;
}

