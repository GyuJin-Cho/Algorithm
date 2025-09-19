#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> arr;

    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        arr.push_back(make_pair(s,e));
    }

    sort(arr.begin(),arr.end(),[](const pair<int,int>& _Left, const pair<int,int>& _Right)
    {
        if(_Left.second == _Right.second)
            return _Left.first < _Right.first;
        return _Left.second < _Right.second;
    });

    int temp = 0;
    int cnt = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(temp<=arr[i].first)
        {
            temp = arr[i].second;
            cnt++;
        }
    }

    cout<<cnt;
    
    return 0;
}