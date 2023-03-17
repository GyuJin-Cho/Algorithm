#include<iostream>
#include <vector>
using namespace std;
int answer[100001];
vector<int> V[100001];
bool visit[100001];
void DFS(int L)
{
	visit[L] = true;
	for(int i=0;i<V[L].size();i++)
	{
		if(!visit[V[L][i]])
		{
			answer[V[L][i]] = L;
			DFS(V[L][i]);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int a,b;
	for(int i=0;i<N-1;i++)
	{
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	DFS(1);

	for (int i = 2; i <= N; i++)
		cout << answer[i] << '\n';

	return 0;
}