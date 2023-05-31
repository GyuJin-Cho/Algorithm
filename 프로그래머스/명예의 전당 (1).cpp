#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<score.size();i++)
    {
	    if(i>k-1)
	    {
            if(pq.top() < score[i])
            {
                pq.pop();
                pq.push(score[i]);
            }
            answer.push_back(pq.top());
	    }
        else
        {
            pq.push(score[i]);
            answer.push_back(pq.top());
        }
    }
    return answer;
}

int main()
{
    vector<int> score = { 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 };
    vector<int> ans = solution(4, score);
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}