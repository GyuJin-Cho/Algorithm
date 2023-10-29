#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(tuple<string, int, int>a, tuple<string, int, int>b)
{
    return get<1>(a) < get<1>(b);
}

int after_study(int start, int time)
{
    int start_h = start / 100, start_m = start % 100;
    int time_h = time / 60, time_m = time % 60;
    return ((start_h + time_h + (start_m + time_m) / 60) * 100 + (start_m + time_m) % 60);
}

int rest_time(tuple<string, int, int> cur, tuple<string, int, int> start, int time)
{
    int h, m;
    h = get<1>(start) / 100 - time / 100;
    m = get<1>(start) % 100 - time % 100;
    time = h * 60 + m;
    return (get<2>(cur) - time);
}

vector<string> solution(vector<vector<string>> plans)
{
    int n = plans.size();
    vector<string> answer;
    deque<tuple<string, int, int>> list, wait;
    for (int i = 0; i < n; i++)
    	list.push_back({ plans[i][0], stoi(plans[i][1]) * 100 + stoi(plans[i][1].substr(3,2)), stoi(plans[i][2]) });
   
    sort(list.begin(), list.end(), compare);
    int time = get<1>(list.front());
    while (!list.empty() || !wait.empty())
    {
        tuple<string, int, int> cur;
        if (!wait.empty() && (list.empty() || time < get<1>(list.front())))
        {
            cur = wait.front();
            wait.pop_front();
        }
        else
        {
            cur = list.front();
            list.pop_front();
            time = get<1>(cur);
        }
        if (!list.empty() && after_study(time, get<2>(cur)) > get<1>(list.front()))
        {
            get<2>(cur) = rest_time(cur, list.front(), time);
            wait.push_front(cur);
            time = get<1>(list.front());
        }
        else
        {
            answer.push_back(get<0>(cur));
            time = after_study(time, get<2>(cur));
        }
    }
    return answer;
}

int main()
{
    vector<vector<string>> p =
    {
        {"science", "12:40", "50"},
        {"music", "12:20", "40"},
        {"history", "14:00", "30"},
        {"computer", "12:30", "100"}
    };

    vector<string> ans = solution(p);

    for(string s : ans)
    {
        cout << s << ' ';
    }

    return 0;
}