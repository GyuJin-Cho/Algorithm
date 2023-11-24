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
	int r, e, c;
	for(int i=0;i<3;i++)
	{
		cin >> r >> e >> c;

		int div = e - c;
		if (r < div)
			cout << "advertise" << '\n';
		else if (r > div)
			cout << "do not advertise" << '\n';
		else
			cout << "does not matter" << '\n';
	}

	return 0;
}