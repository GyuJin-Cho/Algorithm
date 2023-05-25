#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance)
{
    int answer = 0;
    vector<pair<int,int>> ran;
    for(int i=0;i<rank.size();i++)
    {
        if(attendance[i])
        {
            ran.push_back({rank[i],i});
        }
    }
    
    sort(ran.begin(),ran.end());
    
    answer = 10000*ran[0].second+100*ran[1].second+ran[2].second;
    
    return answer;
}

int main()
{
    vector<int> rank = {1,2,3};
    vector<bool> att = {1,1,1};
    
    cout<<solution(rank,att);
    
    return 0;
}
