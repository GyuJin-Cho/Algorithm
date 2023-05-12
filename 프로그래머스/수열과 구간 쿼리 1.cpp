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
            arr[j]++;
	    }
    }

    return arr;
}

int main()
{
    vector<int> arr = { 1,1,1,1 };
    vector<vector<int>> q = { {0,3},{0,3},{0,3} };
    vector<int> ans = solution(arr, q);
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}