#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int answer = 0;

    priority_queue<int> pq;
    int i = 0;

    for(; i<enemy.size();i++)
    {
	    if(n>=enemy[i])
	    {
            n -= enemy[i];
            pq.push(enemy[i]);
	    }
        else
        {
            if (!k)
                break;
            if(!pq.empty()&&(pq.top()>enemy[i]))
            {
                n += pq.top();
                pq.pop();
                n -= enemy[i];
                pq.push(enemy[i]);
            }
            k--;
        }
    }

    return i;
}

int main()
{
    cout << solution(7, 3, { 4, 2, 4, 5, 3, 3, 1 });

    return 0;
}