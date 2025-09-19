#include <bits/stdc++.h>

using namespace std;

#define MAX 10
class Trie
{
public:

    Trie()
    {
        Finish = false;
        for(int i=0;i<MAX;i++)
        {
            Node[i] = nullptr;
        }
    }

    ~Trie()
    {
        for(int i=0;i<MAX;i++)
        {
            if(Node[i])
            {
                delete Node[i];
                Node[i] = nullptr;
            }
        }
    }
    
    void Insert(const string& s, int idx)
    {
        if(s.length() == idx)
        {
            Finish = true;
            return;
        }

        if(!Node[s[idx]-48])
            Node[s[idx]-48] = new Trie();
        Node[s[idx]-48]->Insert(s, idx+1);
    }

    bool Find(const string& s, int idx)
    {
        if(s.length() == idx)
            return false;
        if(Finish)
            return true;
        if(!Node[s[idx]-48])
            return false;
        return Node[s[idx]-48]->Find(s, idx+1);
    }

private:
    Trie* Node[MAX];
    bool Finish;
};

int main()
{
    int t,n;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        string s;
        Trie* trie = new Trie();
        cin>>n;
        vector<string> str(n);
        for(int j=0;j<n;j++)
        {
            cin>>str[j];
            trie->Insert(str[j], 0);
        }

        int z=0;
        for(;z<str.size();z++)
        {
            if(trie->Find(str[z],0))
            {
                cout<<"NO"<<'\n';
                break;
            }
        }
        
        if(z==n)
            cout<<"YES"<<'\n';
        delete trie;
    }
    
    return 0;
}