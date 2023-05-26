#include <iostream>

using namespace std;

int main()
{
    int T,N,Num,sum;
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>Num;
            sum+=Num;
        }
        cout<<sum<<'\n';
    }
    return 0;
}
