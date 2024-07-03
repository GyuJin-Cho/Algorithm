#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const int& scovil : scoville)
        pq.push(scovil);
    while (pq.top() < K)
    {
        if (pq.size() == 1)
            return -1;
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        int res = one + (two * 2);
        pq.push(res);

        answer++;
    }
    return answer;
}

int main()
{
    vector<int> v = { 1,2,3,9,10,12 };
    cout << solution(v, 7);

    return 0;
}