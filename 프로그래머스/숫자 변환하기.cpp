#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

bool visit[1000001];

int BFS(int x, int y, int n)
{
    visit[x] = true;
    queue<pair<int, int>>q;
    q.push({ x,0 });

    while(!q.empty())
    {
        int now,cost;
        tie(now, cost) = q.front();
        q.pop();
        if (now == y)
            return cost;

        if(now+n>=0&&now+n<=y)
        {
	        if(!visit[now+n])
	        {
                q.push({ now + n,cost + 1 });
                visit[now + n] = true;
	        }
        }

        if (now * 2 >= 0 && now * 2 <= y)
        {
            if (!visit[now * 2])
            {
                q.push({ now * 2,cost + 1 });
                visit[now * 2] = true;
            }
        }

        if (now * 3 >= 0 && now * 3 <= y)
        {
            if (!visit[now * 3])
            {
                q.push({ now * 3,cost + 1 });
                visit[now * 3] = true;
            }
        }
    }
    return -1;
}

int solution(int x, int y, int n)
{
    int answer = BFS(x,y,n);
    return answer;
}

int main()
{
    cout << solution(2, 5, 4);

    return 0;
}