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
		int n,num,answer1=1000001,answer2=-1000001;
		cin >> n;
		while(n--)
		{
			cin >> num;
			answer1 = min(answer1, num);
			answer2 = max(answer2, num);
		}
		cout << answer1 << ' ' << answer2 << '\n';
	}

	return 0;
}