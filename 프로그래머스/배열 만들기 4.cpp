#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> stk;

    for(int i=0;i<arr.size();)
    {
	    if(stk.empty())
	    {
            stk.push_back(arr[i]);
            i++;
	    }
        else if(!stk.empty())
        {
	        if(stk[stk.size()-1]<arr[i])
	        {
                stk.push_back(arr[i]);
                i++;
	        }
            else if(stk[stk.size()-1]>=arr[i])
            {
                stk.pop_back();
            }
        }
    }

    return stk;
}

int main()
{
    vector<int> v = { 1,4,2,5,3 };
    vector<int> ans = solution(v);
    for (auto i : ans)
        cout << i << ' ';

    return 0;
}