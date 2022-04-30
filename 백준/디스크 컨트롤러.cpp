#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <queue>

using namespace std;

pair<int, int> s[501];

int solution(vector<vector<int>> jobs)
{
    int answer = 0;

    int size = jobs.size();

    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int,int>>

    return answer;
}

int main()
{
    vector<vector<int>> v = { {0,3},{1,9},{2,6} };

    cout << solution(v);

    return 0;
}