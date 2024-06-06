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
	Trie* Node[10];
	bool Finish;
public:
	Trie();
	void Insert(const string& s, int idx);
	bool Find(const string& s, int idx);
	void Clear();
};
Trie::Trie()
{
	Finish = false;
	for (int i = 0; i < 10; i++)
		Node[i] = nullptr;
}

void Trie::Insert(const string& s, int idx)
{
	if (s.length() == idx)
	{
		Finish = true;
		return;
	}

	if (!Node[s[idx] - '0'])
		Node[s[idx] - '0'] = new Trie();
	Node[s[idx] - '0']->Insert(s, idx + 1);
}

bool Trie::Find(const string& s, int idx)
{
	if (s.length() == idx)
		return false;
	if (Finish)
		return true;
	if (!Node[s[idx] - '0'])
		return false;
	return Node[s[idx] - '0']->Find(s, idx + 1);
}

void Trie::Clear()
{
	for (int i = 0; i < 10; i++)
	{
		if (Node[i])
		{
			Node[i]->Clear();
			delete Node[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		string s;
		Trie* root = new Trie();
		vector<string> v;
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			v.push_back(s);
			root->Insert(s,0);
		}
		int i;
		for (i = 0; i < v.size(); i++)
		{
			if (root->Find(v[i], 0))
			{
				cout << "NO" << '\n';
				break;
			}
		}

		if(i==N)
			cout << "YES" << '\n';
		root->Clear();
		delete root;
	}

	return 0;
}


