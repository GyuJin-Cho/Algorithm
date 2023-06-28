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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	if(T==0)
	{
		cout << 0;
		return 0;
	}
	vector<int> ranks(T);
	for(int i=0;i<T;i++)
	{
		cin >> ranks[i];
	}

	sort(ranks.begin(), ranks.end());
	int absavg = floor(((float)T * 0.15)+0.5f);
	
	
	ranks.erase(ranks.begin(),ranks.begin()+absavg);
	T -= absavg;
	ranks.erase(ranks.end() - absavg,ranks.end());
	T -= absavg;
	int sum = 0;
	for (int i = 0; i < ranks.size(); i++)
		sum += ranks[i];
	int ans = floor(((float)sum/(float)T) + 0.5f);
	cout << ans;

	return 0;
}