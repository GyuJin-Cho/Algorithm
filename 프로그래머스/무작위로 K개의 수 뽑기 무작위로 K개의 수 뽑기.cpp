#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    vector<int> answer;
    
    bool check[100000] = {false,};
    for(int i=0;i<arr.size();i++)
    {
        if(answer.size()==k)
            break;
        if(!check[arr[i]])
        {
            answer.push_back(arr[i]);
            check[arr[i]] = true;
        }
    }
    
    if(answer.size()!=k)
    {
        for(int i=answer.size();i<k;i++)
        {
            answer.push_back(-1);
        }
    }
    
    return answer;
}

int main()
{
    vector<int> arr = {0, 1, 1, 1, 1};
    vector<int> ans = solution(arr, 4);
    for(int i : ans)
        cout<<i<<' ';
    return 0;
}
