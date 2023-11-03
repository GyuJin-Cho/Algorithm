#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>

using namespace std;

class Trie
{
private:
	map<string, Trie*>node;

public:

	void Insert(const vector<string>& foods, int idx)
	{
		if (idx == foods.size())
			return;

		if(node.find(foods[idx])==node.end())
			node[foods[idx]] = new Trie();
		node[foods[idx]]->Insert(foods, idx + 1);
	}

	void Print(int depth)
	{
		for(auto& no : node)
		{
			for (int i = 0; i < depth; i++)
				cout << "--";
			cout << no.first << '\n';
			no.second->Print(depth + 1);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	Trie* root = new Trie();
	while(T--)
	{
		int n;
		cin >> n;
		vector<string> foods(n);
		for(int i=0;i<n;i++)
			cin >> foods[i];

		root->Insert(foods, 0);
	}

	root->Print(0);
	return 0;
}