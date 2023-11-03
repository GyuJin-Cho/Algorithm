#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
constexpr int MAX = 501;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[MAX][MAX][4];
int r, c;

int Simul(int y, int x, int k, const vector<string> &grid)
{
	int cnt = 0;
	while(!visit[y][x][k])
	{
		cnt++;
		visit[y][x][k] = true;
		if(grid[y][x]=='L')
		{
			k = (k + 3) % 4;
		}
		else if(grid[y][x]=='R')
		{
			k = (k + 1) % 4;
		}
		y = (y + dy[k]+r)%r;
		x = (x + dx[k]+c)%c;
	}
	return cnt;
}

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
	r = grid.size();
	c = grid[0].size();

    for(int i=0;i<grid.size();i++)
    {
	    for(int j=0;j<grid[i].length();j++)
	    {
		    for(int k=0;k<4;k++)
		    {
			    if(!visit[i][j][k])
			    {
					answer.push_back(Simul(i, j, k, grid));
			    }
		    }
	    }
    }
	sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> v = solution({ "R","R" });

    for (int i : v)
        cout << i << ' ';
    return 0;
}