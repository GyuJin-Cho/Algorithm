#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct compare 
{
    bool operator()(vector<int> a, vector<int> b) 
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) 
{
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    int time = 0;
    int total_wait_time = 0;
    int job_index = 0;
    int completed_jobs = 0;

    while (completed_jobs < jobs.size()) 
    {
        while (job_index < jobs.size() && jobs[job_index][0] <= time) 
        {
            pq.push(jobs[job_index++]);
        }

        if (pq.empty())
        {
            time = jobs[job_index][0];
        }
        else 
        {
            vector<int> current_job = pq.top();
            pq.pop();

            total_wait_time += time - current_job[0] + current_job[1];
            time += current_job[1];
            completed_jobs++;
        }
    }

    return total_wait_time / jobs.size();
}
int main()
{
    vector<vector<int>> v = { {0, 3}, {1, 9}, {2, 6} };
    cout << solution(v);

    return 0;
}