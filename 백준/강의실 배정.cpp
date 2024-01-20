#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    vector<pair<int,int>> arr;
    
    for(int i=0;i<N;i++)
    {
        int s,e;
        cin>>s>>e;
        arr.push_back({s,e});
    }
    sort(arr.begin(),arr.end(),[](const pair<int,int>&p1, const pair<int,int>&p2)
         {
                if(p1.first==p2.first)
                    return p1.second<p2.second;
                return p1.first<p2.first;
         }
         );
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(arr[0].second);
    for(int i=1;i<N;i++)
    {
        pq.push(arr[i].second);
        if(pq.top()<=arr[i].first)
            pq.pop();
    }
    cout<<pq.size();
    return 0;
}
