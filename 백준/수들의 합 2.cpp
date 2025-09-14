#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> v(N+1);
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }

    int start = -1;
    int end = -1;
    int ans = 0;
    int sum = 0;

    while(start <= end && end < N)
    {
        if(sum == M)
        {
            ans++;
            start++;
            sum -= v[start];
        }
        else if(sum > M)
        {
            start++;
            sum -= v[start];
        }
        else
        {
            end++;
            sum += v[end];
        }
    }
    cout<<ans;
    return 0;
}