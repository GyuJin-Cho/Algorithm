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
#include<cstring>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> v(N);
	for(int i=0;i<N;i++)
	{
		cin >> v[i];
	}
	int sum = 0;
	string answer = "";
	for(int i=0;i<M;i++)
	{
		map<char, int>m;
		for(int j=0;j<N;j++)
		{
			m[v[j][i]]++;
		}
		char ch;
		int MAX = 0;
		for(auto i : m)
		{
			if(MAX<i.second)
			{
				MAX = i.second;
				ch = i.first;
			}
		}
		answer+= ch;
		sum += N - MAX;
	}
	cout << answer << '\n' << sum;
	return 0;
}