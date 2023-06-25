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
    int Location;
    int cnt;
};

int A,B,N,M;
bool visited[100001];
int dl[] = {1,-1};
void BFS()
{
    queue<node> q;
    q.push({N,0});
    visited[N] = true;
    while(!q.empty())
    {
        node n = q.front();
        q.pop();
        if(n.Location==M)
        {
            cout<<n.cnt;
            return;
        }
        
        for(int i=0;i<8;i++)
        {
            int nl;
            if(i<2)
                nl = n.Location + dl[i];
            else if(i==2)
                nl = n.Location + A;
            else if(i==3)
                nl = n.Location - A;
            else if(i==4)
                nl = n.Location + B;
            else if(i==5)
                nl = n.Location - B;
            else if(i==6)
                nl = n.Location * A;
            else
                nl = n.Location * B;
            
            if(nl<0||nl>100000)
                continue;
            
            if(!visited[nl])
            {
                q.push({nl,n.cnt+1});
                visited[nl] = true;
            }
            
        }
        
    }
}

int main()
{
    cin>>A>>B>>N>>M;
    
    BFS();
    
    return 0;
}
