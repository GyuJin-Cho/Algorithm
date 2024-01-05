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
bool ans[58][58];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	cin.ignore();
	for (int i = 0; i < n; i++) 
	{
		string input;
		getline(cin, input);
		if (input[0] == input[input.length() - 1])
			continue;
		if (ans[input[0] - 'A'][input[input.length() - 1] - 'A']) 
			continue;
		cnt++;
		ans[input[0] - 'A'][input[input.length() - 1] - 'A'] = true;
	}

	for (int k = 0; k < 58; k++) 
	{
		for (int i = 0; i < 58; i++) 
		{
			for (int j = 0; j < 58; j++)
			{
				if (ans[i][j] || i == j)
					continue;
				ans[i][j] = ans[i][k] && ans[k][j];
				if (ans[i][j])
					cnt++;
			}
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < 58; i++) 
	{
		for (int j = 0; j < 58; j++) 
		{
			if (ans[i][j]) 
			{
				cout << (char)(i + 'A') << " => " << (char)(j + 'A') << '\n';
			}
		}
	}
	return 0;
}