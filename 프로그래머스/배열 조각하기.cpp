#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query)
{
    for(int i=0;i<query.size();i++)
    {
	    if(i%2==0)
	    {
            arr.erase(arr.begin() + query[i]+1, arr.end());
	    }
        else
        {
            arr.erase(arr.begin(), arr.begin() + query[i]);
        }
    }

    return arr;
}

int main()
{
    vector<int> arr = { 0,1,2,3,4,5 };
    vector<int> query = { 4,1,2 };
    vector<int> ans = solution(arr, query);
    for (auto i : ans)
        cout << i << ' ';

    return 0;
}