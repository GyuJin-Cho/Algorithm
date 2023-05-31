#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin>>N;
    cin.ignore();
    string s;
    while(N--)
    {
        getline(cin,s);
        vector<string> v;
        string tmp="";
        for(int i=0;i <s.size();i++)
        {
            if(s[i]==' ')
            {
                v.push_back(tmp);
                tmp.clear();
                continue;
            }
            tmp+=s[i];
        }
        
        if(!tmp.empty())
            v.push_back(tmp);
        
        for(int i=0;i<v.size();i++)
        {
            reverse(v[i].begin(),v[i].end());
        }
        
        for(auto i : v)
        {
            cout<<i<<' ';
        }
    }
    
    return 0;
}
