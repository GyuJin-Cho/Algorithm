#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> s;
	int N, M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		s.push_back(i);
	}
	int start, end;

	for(int i=0;i<M;i++)
	{
		cin >> start >> end;
		reverse(s.begin() + start-1, s.begin() + end);
	}
	for(int i : s)
	{
		cout << i << ' ';
	}

	return 0;
}