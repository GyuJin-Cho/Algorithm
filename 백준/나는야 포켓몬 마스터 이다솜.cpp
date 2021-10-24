#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	unordered_map<string, int> m1;
	unordered_map<int, string> m2;
	if (N == 0 || M == 0)
		return 0;
	if (N > 100000 || M > 100000)
		return 0;
	for (int i = 1; i <= N; i++)
	{
		string a;
		cin >> a;
		m1.insert({ a,i });
	}

	for (auto i : m1)
	{
		m2.insert({ i.second,i.first });
	}
	
	for (int i = 0; i < M; i++)
	{
		string a="";
		cin >> a;
		if (a[0]<'A')
		{
			cout << m2[stoi(a)] << '\n';
		}
		else
		{
			cout << m1[a] << '\n';
		}
	}

	return 0;
}