#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool visit[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cnt = 0;
void DFS(const vector<string>& maps,int y, int x)
{
    visit[y][x] = true;
    cnt += maps[y][x] - 48;
    int n = maps.size();
    int m = maps[0].size();
    if(y==n&&x==m)
    {
        return;
    }

    for(int i=0;i<4;i++)
    {
        int ny = dy[i]+y;
        int nx = dx[i]+x;
        if(ny>=0&&nx>=0&&ny<n&&nx<m)
        {
	        if(!visit[ny][nx]&& maps[ny][nx] >= '1' && maps[ny][nx] <= '9')
	        {
                DFS(maps, ny, nx);
	        }
        }
    }
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;


    for(int i=0;i<maps.size();i++)
    {
	    for(int j=0;j<maps[i].length();j++)
	    {
			if(!visit[i][j]&&maps[i][j]>='1'&&maps[i][j]<='9')
			{
                cnt = 0;
                DFS(maps, i, j);
                answer.push_back(cnt);
			}
	    }
    }

    if (answer.size() > 0)
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);
    return answer;
}

int main()
{
    vector<string> v = { "X5XX5X", "111111", "XXXXXX", "111111" };
    vector<int>answer = solution(v);
    for(auto i : answer)
    {
        cout << i << '\n';
    }

    return 0;
}