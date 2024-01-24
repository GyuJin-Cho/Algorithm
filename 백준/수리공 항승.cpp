#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N,L;
    cin>>N>>L;
    vector<int> arr(N);
    
    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    sort(arr.begin(),arr.end());
    
    int start = arr[0];
    int ans = 1;
    for(int i=1;i<N;i++)
    {
        if(L<=arr[i] - start)
        {
            ans++;
            start = arr[i];
        }
    }

    cout<<ans;
    return 0;
}
