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
const int INF = 6;
int main()
{
	int n;

	while(1)
	{
		cin >> n;
		if (n == 0)
			break;
		vector<int> lottos(n);
		for (int i = 0; i < n; i++)
			cin >> lottos[i];
		vector<bool> ch(n,true);
		for (int i = 0; i < INF; i++)
			ch[i] = false;
		do
		{
			for(int i=0;i<lottos.size();i++)
			{
				if (!ch[i])
					cout << lottos[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(ch.begin(), ch.end()));
		cout << '\n';
	}

	return 0;
}