#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    sort(v.begin(),v.end());

    long long start = 0;
    long long end = v[n-1];
    long long ans = 0;
    
    while(start<=end)
    {
        long long mid = (start+end)/2;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            if(v[i]-mid > 0)
                sum = sum + (v[i] - mid);
        }
        if(sum >= m)
        {
            ans = mid;
            start = mid+1;
        }
        else if(sum < m)
        {
            end = mid-1;
        }
    }
    cout<<ans;
    return 0;
}