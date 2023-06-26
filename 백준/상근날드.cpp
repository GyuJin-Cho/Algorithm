#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int ans=217400000;
    vector<int> hamburger(3);
    vector<int> drink(2);
    for(int i=0;i<3;i++)
    {
        cin>>hamburger[i];
    }
    for(int i=0;i<2;i++)
    {
        cin>>drink[i];
    }
    const int SetPrice = -50;
    for(int i=0;i<3;i++)
    {
        int sum = 0;
        for(int j=0;j<2;j++)
        {
            sum = hamburger[i]+drink[j]+SetPrice;
            ans = min(sum,ans);
        }
    }
    cout<<ans;
    return 0;
}
