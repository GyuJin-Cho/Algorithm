#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(string& A, string& B)
{
	if (A.length() == B.length())
	{
		return A<B;
	}
	return A.length() < B.length();
}
int main()
{

	cin.tie(0);
	int n;
	vector<string> V;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (find(V.begin(), V.end(), str) == V.end())
		{
			V.push_back(str);
		}
	}
	sort(V.begin(), V.end(),comp);
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << '\n';
	}
	return 0;
}