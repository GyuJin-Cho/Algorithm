#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

char str[1000];

struct Node
{
	char Left;
	char Right;

};
map<char, Node> Map;
void Pre(char node)
{
	
	if (node == '.')
		return;
	cout << node;
	Pre(Map[node].Left);
	Pre(Map[node].Right);
}

void In(char node)
{

	if (node == '.')
		return;
	In(Map[node].Left);
	cout << node;
	In(Map[node].Right);
}

void Post(char node)
{

	if (node == '.')
		return;
	Post(Map[node].Left);
	Post(Map[node].Right);
	cout << node;
}
int main()
{
	int N;
	cin >> N;
	string s;
	cin.ignore();
	for(int i=0;i<N;i++)
	{
		getline(cin, s);
		Map[s[0]].Left = s[2];
		Map[s[0]].Right = s[4];
	}
	Pre('A');
	cout << '\n';

	In('A');
	cout << '\n';

	Post('A');
	cout << '\n';
	return 0;
}