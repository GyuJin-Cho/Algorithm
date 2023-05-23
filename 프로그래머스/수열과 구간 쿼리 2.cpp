#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
#define INF 21740000
vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> ans;
    for(int i=0;i<queries.size();i++)
    {
        int tmp = INF;
        for(int j=queries[i][0];j<=queries[i][1];j++)
        {
	        if(arr[j]>queries[i][2])
	        {
                tmp = min(tmp, arr[j]);
	        }
        }
        if (tmp == INF)
            ans.push_back(-1);
        else
            ans.push_back(tmp);
    }
    return ans;
}

int main()
{
    vector<int> v = { 0, 1, 2, 4, 3 };
    vector<vector<int>> q = { {0,4,2},{0,3,2},{0,2,2} };
    vector<int> answer = solution(v, q);
    for (auto i : answer)
        cout << i << ' ';
    return 0;
}