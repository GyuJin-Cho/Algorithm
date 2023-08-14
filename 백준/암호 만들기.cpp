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

using namespace std;

bool check(string& password)
{
	int ja = 0;
	int mo = 0;
	for (char x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			mo++;
		}
		else
		{
			ja++;
		}
	}
	return ja >= 2 && mo >= 1;
}


void DFS(int n, vector<char>&alpha,string password, int Depth)
{
	if(password.length()==n)
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}
	if (Depth >= alpha.size())
		return;
	DFS(n, alpha, password + alpha[Depth], Depth + 1);
	DFS(n, alpha, password, Depth + 1);
}
int main()
{
	int l, c;
	cin >> l >> c;
	vector<char> alpha(c);
	for (int i = 0; i < c; i++)
	{
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());
	DFS(l, alpha, "", 0);

	return 0;
}