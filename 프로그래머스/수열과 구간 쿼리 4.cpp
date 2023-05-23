#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    for(int i=0;i<queries.size();i++)
    {
	    for(int j=queries[i][0];j<=queries[i][1];j++)
	    {
            if (j % queries[i][2] == 0)
                arr[j]++;
	    }
    }

    return arr;
}

int main()
{
    vector<int> arr = { 0,1,2,4,3 };
    vector<vector<int>> qu = { {0,4,1},{0,3,2},{0,3,3} };
    vector<int> ans = solution(arr, qu);
    for (auto i : ans)
        cout << i << ' ';

    return 0;
}