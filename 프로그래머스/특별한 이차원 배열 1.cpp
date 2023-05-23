#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.clear();
	    for(int j=0;j<n;j++)
	    {
		    if(i==j)
		    {
                v.push_back(1);
		    }
            else
            {
                v.push_back(0);
            }
	    }
        answer.push_back(v);
    }

    return answer;
}

int main()
{
    vector<vector<int>> ans = solution(1);

    for(auto i : ans)
    {
	    for(auto j : i)
	    {
            cout << j << ' ';
	    }
        cout << '\n';
    }

    return 0;
}