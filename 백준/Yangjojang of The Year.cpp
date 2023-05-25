#include<iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int N;
    cin>>N;
    string s;
    int Soju;
    int M;
    while(N--)
    {
        cin>>M;
        unordered_map<string, int> um;
        for(int i=0;i<M;i++)
        {
        
            cin>>s>>Soju;
            um[s] = Soju;
        }
        pair<string,int> p = {"",-21740000};
        for(auto i : um)
        {
            if(i.second>p.second)
            {
                p.first = i.first;
                p.second = i.second;
            }
        }
        cout<<p.first<<'\n';
    }
    
    return 0;
}
