#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{

    for(int i=0;i<queries.size();i++)
    {
        int tmp = arr[queries[i][0]];
        arr[queries[i][0]] = arr[queries[i][1]];
        arr[queries[i][1]] = tmp;
    }

    return arr;
}

int main()
{
    vector<int> v = { 0,1,2,3,4 };
    vector<vector<int>> q = { {0,3},{1,2},{1,4} };
    vector<int> ans = solution(v, q);
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}