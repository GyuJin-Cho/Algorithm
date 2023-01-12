#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> emergency)
{
    vector<int> answer;
    map<int, int> m;
    for(int i=0;i<emergency.size();i++)
    {
        m[emergency[i]] = 1;
    }

    for(auto i:m)
    {
        for(int j=0;j<emergency.size();j++)
        {
            if (emergency[j] > i.first)
                m[i.first]++;
        }
    }

    for(int i=0;i<emergency.size();i++)
    {
	    for(auto j : m)
	    {
		    if(j.first==emergency[i])
		    {
                answer.push_back(j.second);
		    }
	    }
    }

    return answer;
}

int main()
{
    vector<int> v = { 30, 10, 23, 6, 100 };
    vector<int> ans = solution(v);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}