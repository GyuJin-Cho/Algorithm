#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals)
{
    vector<int> answer;

    for(int i=0;i<intervals.size();i++)
    {
	    for(int j=intervals[i][0];j<=intervals[i][1];j++)
	    {
            answer.push_back(arr[j]);
	    }
    }

    return answer;
}

int main()
{
    vector<int> arr = { 1,2,3,4,5 };
    vector<vector<int>> arr2 = { {1,3},{0,4} };
    vector<int> v = solution(arr, arr2);
    for(auto i : v)
    {
        cout << i << ' ';
    }
    return 0;
}