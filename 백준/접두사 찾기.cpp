#include <bits/stdc++.h>

using namespace std;
#define MAX 26
class Trie
{
public:
    Trie()
    {
        Finish = false;
        for(int i=0;i<MAX;i++)
            Node[i] = nullptr;
    }

    ~Trie()
    {
        for(int i=0;i<MAX;i++)
        {
            delete Node[i];
            Node[i] = nullptr;
        }
    }

    void Insert(const string& _s, int _idx)
    {
        if(_s.length() == _idx)
        {
            Finish = true;
            return;
        }

        if(!Node[_s[_idx]-'a'])
            Node[_s[_idx]-'a'] = new Trie();
        Node[_s[_idx]-'a']->Insert(_s,_idx+1);
    }

    bool Find(const string& _s, int _idx)
    {
        if(_s.length() == _idx)
            return true;
        if(Finish)
            return true;
        if(!Node[_s[_idx]-'a'])
            return false;

        return Node[_s[_idx]-'a']->Find(_s,_idx+1);
    }

private:
    Trie* Node[MAX];
    bool Finish;
};

int main()
{
    int n,m;
    cin>>n>>m;
    Trie* trie = new Trie();
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        trie->Insert(s,0);
    }

    int ans=0;
    for(int i=0;i<m;i++)
    {
        cin>>s;
        
        if(trie->Find(s,0))
        {
            ans++;
        }
    }

    cout<<ans;
    delete trie;
    return 0;
}