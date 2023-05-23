#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag)
{
    vector<int> answer;

    for(int i=0;i<flag.size();i++)
    {
	    if(flag[i])
	    {
		    for(int j=0;j<arr[i]*2;j++)
		    {
                answer.push_back(arr[i]);
		    }
	    }
        else
        {
	        for(int j=0;j<arr[i];j++)
	        {
                answer.pop_back();
	        }
        }
    }

    return answer;
}

int main()
{
    vector<int> arr = { 3,2,4,1,3 };
    vector<bool> flag = { 1,0,1,0,0 };
    vector<int> ans = solution(arr, flag);

    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}