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

using namespace std;

int main()
{
	int N;
	while (1) 
	{
		int k; 
		cin >> k;
		if (k == 0) 
			break;

		vector<int> v(k);
		for (int i = 0; i < k; i++)
			cin >> v[i];

		vector<bool> lotto(k, true);

		for (int i = 0; i < 6; i++)
			lotto[i] = false;
		do 
		{
			for (int i = 0; i < v.size(); i++) 
			{
				if (!lotto[i]) 
					cout << v[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(lotto.begin(), lotto.end()));

		cout << '\n';
	}
	return 0;
}