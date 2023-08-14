#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> v;
	vector<bool> ch(N, true);
	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}
	for (int i = 0; i < M; i++)
	{
		ch[i] = false;
	}
	do
	{
		for (int i = 0; i < v.size(); i++)
		{
			if(!ch[i])
				cout << v[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(ch.begin(), ch.end()));

	return 0;
}