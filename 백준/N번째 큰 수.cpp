#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    vector<int> v(n*n);
    for(int i=0;i<n*n;i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end(), greater<int>());

    cout<<v[n-1];
    return 0;
}