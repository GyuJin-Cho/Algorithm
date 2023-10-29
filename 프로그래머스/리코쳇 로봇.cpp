#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct node
{
    int y;
    int x;
    int cnt;
};

int answer = 0;
bool visit[101][101];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void BFS(const vector<string> &board,int sy, int sx, int gy, int gx)
{
    queue<node> q;
    q.push({ sy,sx,0 });
    visit[sy][sx] = true;
    while(!q.empty())
    {
        node n = q.front();
        q.pop();
        if(n.y==gy&&n.x==gx)
        {
            answer = n.cnt;
            return;
        }

        for(int i=0;i<4;i++)
        {
            int ny = dy[i] + n.y;
            int nx = dx[i] + n.x;
            if(ny>-1&&nx>-1&&ny<board.size()&&nx<board[0].size()&&board[ny][nx]!='D')
            {
	            if(i==0)
	            {
		            while(true)
		            {
                        nx++;
                        if(nx >= board[0].size() )
                        {
                            nx--;
                            break;
                        }
                        else if (board[ny][nx] == 'D')
                        {
                            nx--;
                            break;
                        }
		            }
                    if(!visit[ny][nx])
                    {
                        q.push({ ny,nx,n.cnt + 1 });
                        visit[ny][nx] = true;
                    }
	            }
            	else if (i == 1)
                {
                    while (true)
                    {
                        ny++;
                        if (ny >= board.size())
                        {
                            ny--;
                            break;
                        }
                        else if(board[ny][nx] == 'D')
                        {
                            ny--;
                            break;
                        }
                    }
                    if (!visit[ny][nx])
                    {
                        q.push({ ny,nx,n.cnt + 1 });
                        visit[ny][nx] = true;
                    }
                }
                else if (i == 2)
                {
                    while (true)
                    {
                        nx--;
                        if (nx < 0)
                        {
                            nx++;
                            break;
                        }
                        else if (board[ny][nx] == 'D')
                        {
                            nx++;
                            break;
                        }
                    }
                    if (!visit[ny][nx])
                    {
                        q.push({ ny,nx,n.cnt + 1 });
                        visit[ny][nx] = true;
                    }
                }
                else if (i == 3)
                {
                    while (true)
                    {
                        ny--;
                        if (ny < 0)
                        {
                            ny++;
                            break;
                        }
                        else if (board[ny][nx] == 'D')
                        {
                            ny++;
                            break;
                        }
                    }
                    if (!visit[ny][nx])
                    {
                        q.push({ ny,nx,n.cnt + 1 });
                        visit[ny][nx] = true;
                    }
                }
            }
        }

    }
    answer = -1;
}

int solution(vector<string> board)
{
    vector<vector<string>> b;
    int sy, sx, gy, gx;
    for(int i=0;i<board.size();i++)
    {
	    for(int j=0;j<board[i].length();j++)
	    {
		    if(board[i][j]=='R')
		    {
                board[i][j] = '.';
                sy = i;
                sx = j;
		    }
            else if(board[i][j]=='G')
            {
                board[i][j] = '.';
                gy = i;
                gx = j;
            }
	    }
    }
    BFS(board,sy,sx,gy,gx);
    return answer;
}

int main()
{
    cout << solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });

    return 0;
}