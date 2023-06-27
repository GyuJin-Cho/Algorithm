#include <iostream>

using namespace std;

int main()
{
    int T,a,b;
    cin>>T;
    while(T--)
    {
        int ans=1;
        cin>>a>>b;
        for(int i=0;i<b;i++)
        {
            ans = (ans*a)%10;
        }
        if(ans==0)
            cout<<10<<'\n';
        else
            cout<<ans<<'\n';
    }
    
    return 0;
}
