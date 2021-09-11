#include <string>
#include <vector>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>>q;

    priority_queue<int>pq;

    for(int i=0;i<priorities.size();i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    int count = 0;
    while(!q.empty())
    {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if (pq.top() == value)
        {
            pq.pop();
            count++;
            if (index == location)
            {
                answer = count;
                break;
            }
        }
        else
            q.push(make_pair(index, value));
    }
    return answer;
}

int main()
{
    vector<int> p = { 2,1,3,2 };
    int location = 1;
    cout << solution(p, location);
    return 0;
}