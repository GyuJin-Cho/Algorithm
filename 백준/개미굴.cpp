#include <bits/stdc++.h>

using namespace std;

class Trie
{
private:
    map<string, unique_ptr<Trie>> Node;
public:

    ~Trie()
    {
        Node.clear();
    }
    void Insert(const vector<string>& v, int idx)
    {
        if (v.size() == idx)
            return;
        if (!Node[v[idx]])
            Node[v[idx]] = make_unique<Trie>();
        Node[v[idx]]->Insert(v, idx + 1);
    }
    void Print(int Depth)
    {
        for (const auto& no : Node)
        {
            for (int i = 0; i < Depth; i++)
            {
                cout << "--";
            }
            cout << no.first << '\n';
            no.second->Print(Depth + 1);
        }
    }
};

int main()
{
    int T;
    cin >> T;
    Trie* root = new Trie();
    while (T--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        root->Insert(v, 0);

    }
    root->Print(0);
    delete root;

    return 0;
}