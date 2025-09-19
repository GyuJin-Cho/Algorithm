#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cost;
    cin>>n>>cost;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    sort(v.begin(),v.end(),greater<>());
    int ans = 0;
    for(const int& i : v)
    {
        if(i<=cost)
        {
            int tmp = cost / i;
            cost = cost % i;
            ans += tmp;
        }
    }
    cout<<ans;
    return 0;
}