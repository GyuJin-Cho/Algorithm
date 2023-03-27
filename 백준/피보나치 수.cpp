#include<iostream>

using namespace std;

int main()
{
    long long N;
    cin>>N;
    long long result[45];
    
    result[0] = 0;
    result[1] = 1;
    
    for(int i=2;i<=N;i++)
    {
        result[i] = result[i-1]+result[i-2];
    }
    
    cout<<result[N];
    return 0;
}
