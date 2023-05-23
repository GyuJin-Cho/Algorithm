#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
#define MIN 21740000
int main()
{
    long long N,M;
    cin>>N>>M;
    long long sum=0;
    long long Min = MIN;
    for(long long i=N;i<=M;i++)
    {
        int s = sqrt(i);
        if((s*s)==i)
        {
            Min = min(Min,i);
            sum+=i;
        }
    }
    if(Min==MIN)
        cout<<-1;
    else
        cout<<sum<<'\n'<<Min;
    return 0;
}
