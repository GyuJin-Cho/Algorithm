#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for(int i=0;i<arr.size();i++)
    {
	    for(int j=0;j<arr[i];j++)
	    {
            answer.push_back(arr[i]);
	    }
    }

    return answer;
}

int main()
{
    vector<int> v = { 5,1,4 };
    vector<int> ans = solution(v);
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}