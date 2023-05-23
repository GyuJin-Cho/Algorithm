#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer = arr;
    if(arr.size()==1)
        return arr;
    while(1)
    {
        int num = 2;
        while(num<=answer.size())
        {
            if(num==answer.size())
            {
                return answer;
            }
            num*=2;
        }
        answer.push_back(0);
    }
}

int main()
{
    vector<int> arr = {1};
    vector<int> ans = solution(arr);
    
    for(int i : ans)
        cout<<i<<' ';
    
    return 0;
}
