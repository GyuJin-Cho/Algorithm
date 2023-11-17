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
	int n;
	cin >> n;
	while(n--)
	{
		int N, M;
		cin >> N >> M;
		for(int i=0;i<M;i++)
		{
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1<<'\n';
	}
	return 0;
}