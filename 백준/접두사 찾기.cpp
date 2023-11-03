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
public:
	Trie* node[26];

	Trie()
	{
		for (int i = 0; i < 26; i++)
			node[i] = nullptr;
	}

	void insert(const string& str, int idx)
	{
		if (idx == str.length())
			return;

		if(node[str[idx]-'a']==nullptr)
			node[str[idx] - 'a'] = new Trie();
		
		node[str[idx] - 'a']->insert(str, idx + 1);
	}

	bool find (const string& str, int idx)
	{
		if (idx == str.length())
			return true;

		if (node[str[idx] - 'a'] == nullptr)
			return false;

		return node[str[idx] - 'a']->find(str, idx + 1);
	}

	void Clear()
	{
		for(int i=0;i<26;i++)
		{
			if(node[i])
			{
				node[i]->Clear();
				delete node[i];
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string str;

	Trie* root = new Trie();

	for(int i=0;i<n;i++)
	{
		cin >> str;
		root->insert(str,0);
	}

	int ans = 0;
	for(int i=0;i<m;i++)
	{
		cin >> str;

		if (root->find(str, 0))
			ans++;
	}
	cout << ans;
	root->Clear();
	delete(root);
	return 0;
}