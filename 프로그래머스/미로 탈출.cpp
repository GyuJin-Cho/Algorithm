#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int y;
    int x;
    int cnt;
};
bool visit[101][101];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int solution(vector<string> maps)
{
    int answer = 0;
    int sy, sx, gy, gx, ly, lx;
    for(int i=0;i<maps.size();i++)
    {
	    for(int j=0;j<maps[i].size();j++)
	    {
		    if(maps[i][j]=='S')
		    {
                sy = i;
                sx = j;
		    }
            else if(maps[i][j]=='L')
            {
                ly = i;
                lx = j;
            }
            else if(maps[i][j]=='E')
            {
                gy = i;
                gx = j;
            }
	    }
    }

    queue<node> q;
    q.push({ sy,sx,0 });
    visit[sy][sx] = true;
    bool lch = false;
    int lcnt = 0;
    bool goal = false;
    while(!q.empty())
    {
        node n = q.front();
        q.pop();
	    if(n.y==ly&&n.x==lx&&!lch)
	    {
            lch = true;
            lcnt = n.cnt;
            while (!q.empty())
                q.pop();
            q.push({ ly,lx,0 });
            memset(visit, false, sizeof(visit));
	    }
        else if(n.y ==gy&& n.x ==gx&&lch)
        {
            answer = lch + n.cnt;
            goal = true;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int ny = dy[i] + n.y;
            int nx = dx[i] + n.x;
            if(ny>-1&&nx>-1&&ny<maps.size()&&nx<maps[0].size())
            {
	            if(!visit[ny][nx]&&maps[ny][nx]!='X')
	            {
                    q.push({ ny,nx,n.cnt + 1 });
                    visit[ny][nx] = true;
	            }
            }
        }

    }

    
    return goal ? answer - 1 : -1;
}

int main()
{
    cout << solution({ "LOOOS","OOOOX","OOOOO","OOOOO","EOOOO" });

    return 0;
}