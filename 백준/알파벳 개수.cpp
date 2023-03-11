#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char,int> m;
    for(char i = 'a' ;i<='z';i++)
    {
        m[i]=0;
    }
    
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        m[s[i]]++;
    }
    for(auto i : m)
    {
        cout<<i.second<<" ";
    }
    return 0;
}
