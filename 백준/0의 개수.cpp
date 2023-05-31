#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int a,b;
    while(N--)
    {
        cin>>a>>b;
        string tmp = "";
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            tmp = to_string(i);
            for(int j=0;j<tmp.size();j++)
            {
                if(tmp[j]=='0')
                    cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    
    return 0;
}
