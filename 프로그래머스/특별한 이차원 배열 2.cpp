#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr)
{
    for(int i=0;i<arr.size();i++)
    {
	    for(int j=0;j<arr.size();j++)
	    {
		    if(arr[i][j]!=arr[j][i])
		    {
                return 0;
		    }
	    }
    }
    return 1;
}

int main()
{
    vector<vector<int>> arr = { {5,192,33},{192,72,95},{33,95,999} };
    cout << solution(arr);

    return 0;
}