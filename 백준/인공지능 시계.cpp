#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int H,M,S,T;
    cin>>H>>M>>S;
    cin>>T;
    
    if(T/3600>0)
    {
        H = H+(T/3600);
        T = T-((T/3600)*3600);
    }
    if(T/60>0)
    {
        M = M+(T/60);
        T = T-((T/60)*60);
    }
    S = S+T;
    
    if(S>=60)
    {
        M = M+(S/60);
        S = S%60;
    }
    if(M>=60)
    {
        H = H+(M/60);
        M = M%60;
    }
    if(H>=24)
    {
        H = H%24;
    }
    
    cout<<H<<' '<<M<<' '<<S;
    
    return 0;
}
