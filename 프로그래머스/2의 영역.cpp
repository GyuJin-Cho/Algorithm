#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    vector<int> index;
    for(int i=0;i<arr.size();i++)
    {
	    if(arr[i]==2)
	    {
            index.push_back(i);
	    }
    }
    if(index.empty())
    {
        answer.push_back(-1);
        return answer;
    }
    for(int i=index[0];i<=index[index.size()-1];i++)
    {
        answer.push_back(arr[i]);
    }
    
    return answer;
}

int main()
{
    vector<int> v = { 1, 1, 1 };
    vector<int> ans = solution(v);
    for (int i : ans)
        cout << i<<' ';
    return 0;
}