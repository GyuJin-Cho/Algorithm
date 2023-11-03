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
	bool Finish;
	Trie* node[10];
	Trie()
	{
		Finish = false;
		for (int i = 0; i < 10; i++)
			node[i] = nullptr;
	}

	void insert(const string& str,int idx)
	{
		if (idx == str.length())
		{
			Finish = true;
			return;
		}
			
		if (node[str[idx] - 48] == nullptr)
			node[str[idx] - 48] = new Trie();
		node[str[idx] - 48]->insert(str, idx + 1);
	}

	bool find(const string& str, int idx)
	{
		if (idx == str.length())
			return false;

		if (Finish)
			return true;

		if (node[str[idx] - 48] == nullptr)
			return false;

		return node[str[idx] - 48]->find(str, idx + 1);
	}

	void clear()
	{
		for(int i=0;i<10;i++)
		{
			if(node[i])
			{
				node[i]->clear();
				delete node[i];
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T,n;
	cin >> T;
	while(T--)
	{
		cin >> n;
		Trie* root = new Trie();
		string str;
		vector<string> v;
		for(int i=0;i<n;i++)
		{
			cin >> str;
			v.push_back(str);
			root->insert(str, 0);
		}
		int i;
		for(i=0;i<v.size();i++)
		{
			if(root->find(v[i],0))
			{
				cout << "NO" << '\n';
				break;
			}
		}
		if (i == n)
			cout << "YES" << '\n';

		root->clear();
		delete root;
	}

	return 0;
}