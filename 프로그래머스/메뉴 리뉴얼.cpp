#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
map<string, int> combination;
void DFS(string &order, int &len, string tmp, int idx)
{
    if (tmp.length() == len)
    {
        combination[tmp]++;
        return;
    }
	for(int i=idx;i<order.length();i++)
    {
        DFS(order, len, tmp + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for(int& len : course)
    {
	    for(string order : orders)
	    {
            sort(order.begin(), order.end());
            DFS(order, len, "", 0);
	    }
        int maxcount = 0;
        for(auto it : combination)
        {
            maxcount = max(maxcount, it.second);
        }
        for(auto it : combination)
        {
            if (maxcount < 2)
                break;
            else if (combination[it.first] == maxcount)
                answer.push_back(it.first);
        }
        combination.clear();
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> ans = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
    for(auto& i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}