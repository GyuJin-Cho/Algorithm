#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    sort(v.begin(),v.end());

    vector<int> temp(n);
    int sum = 0;
    
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        temp[i] = sum;
    }
    
    int answer = 0;
    for(int i=0;i<temp.size();i++)
    {
        answer+=temp[i];
    }

    cout<<answer;
    
    return 0;
}