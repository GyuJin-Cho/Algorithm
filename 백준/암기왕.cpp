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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n, m, num;
		unordered_set<int> note1;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> num;
			note1.insert(num);
		}

		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			if(note1.find(num)!=note1.end())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}