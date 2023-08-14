#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}
	do
	{
		for (int i = 0; i < M; i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
		reverse(v.begin() + M, v.end());
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}