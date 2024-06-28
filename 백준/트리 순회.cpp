#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node
{
	char Right;
	char Left;
};
map<char, Node> m;

void Pre(char Node)
{
	if (Node == '.')
		return;
	cout << Node;
	Pre(m[Node].Left);
	Pre(m[Node].Right);
}

void Mid(char Node)
{
	if (Node == '.')
		return;
	Mid(m[Node].Left);
	cout << Node;
	Mid(m[Node].Right);
}

void Post(char Node)
{
	if (Node == '.')
		return;
	Post(m[Node].Left);
	Post(m[Node].Right);
	cout << Node;
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		m[s[0]].Left = s[2];
		m[s[0]].Right = s[4];
	}

	Pre('A');
	cout << '\n';
	Mid('A');
	cout << '\n';
	Post('A');
	cout << '\n';

	return 0;
}