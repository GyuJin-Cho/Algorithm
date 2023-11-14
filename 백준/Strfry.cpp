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
	int N;
	cin >> N;
	while(N--)
	{
		string a, b;
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a == b)
			cout << "Possible" << '\n';
		else
			cout << "Impossible" << '\n';
	}

	return 0;
}