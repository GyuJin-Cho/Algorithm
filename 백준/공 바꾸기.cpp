#include<iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v(N+1);
	for(int i=1;i<=N;i++)
	{
		v[i] = i;
	}
	int a, b,tmp;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		tmp = v[a];
		v[a] = v[b];
		v[b] = tmp;
	}

	for(int i=1;i<v.size();i++)
	{
		cout << v[i] << ' ';
	}
	return 0;
}