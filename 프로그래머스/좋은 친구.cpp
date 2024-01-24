#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;
    vector<string> arr(N+1);
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    
    long long answer = 0;
    queue<int> q[25];
    
    for(int i=1;i<=N;i++)
    {
        int len = arr[i].length();
        while(!q[len].empty()&&i-q[len].front()>K)
            q[len].pop();
        answer += q[len].size();
        q[len].push(i);
    }
    
    cout<<answer;
    
    return 0;
}
