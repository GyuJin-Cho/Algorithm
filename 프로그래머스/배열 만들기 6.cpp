#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    int i=0;
    while(i<arr.size())
    {
        if(answer.empty())
        {
            answer.push_back(arr[i]);
            i++;
        }
        else if(!answer.empty())
        {
            if(answer[answer.size()-1]==arr[i])
            {
                answer.pop_back();
                i++;
            }
            else if(answer[answer.size()-1]!=arr[i])
            {
                answer.push_back(arr[i]);
                i++;
            }
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}

int main()
{
    vector<int> arr = {0,1,1,1,0};
    
    vector<int> ans = solution(arr);
    for(int i : ans)
        cout<<i<<' ';
    
    return 0;
}
