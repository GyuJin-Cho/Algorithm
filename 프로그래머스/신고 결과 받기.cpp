#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(), 0);

    unordered_map<string, int> id_idx_map;

    unordered_map<string, set<string>> report_map;

    for (auto i = 0; i < id_list.size(); ++i) 
    {
        id_idx_map[id_list[i]] = i;
    }

    for (auto rep : report)
    {

        stringstream ss(rep);
        string from, to;
        ss >> from >> to;

        report_map[to].insert(from);

    }

    for (auto iter : report_map) 
    {
        if (iter.second.size() >= k) 
        {
            for (auto in_iter : iter.second) 
            {
                answer[id_idx_map[in_iter]]++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> id = { "muzi", "frodo", "apeach", "neo" };
    vector<string> rep = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    vector<int> v = solution(id, rep, 2);
    for (auto i : v)
        cout << i << ' ';

    return 0;
}