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
	int T;
	cin >> T;
	unordered_map<string, int>um;
	while(T--)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0 || b == 0)
			um["AXIS"]++;
		else if (a > 0 && b > 0)
			um["Q1"]++;
		else if (a < 0 && b>0)
			um["Q2"]++;
		else if (a < 0 && b < 0)
			um["Q3"]++;
		else if (a > 0 && b < 0)
			um["Q4"]++;
	}

	cout << "Q1: " << um["Q1"] << '\n';
	cout << "Q2: " << um["Q2"] << '\n';
	cout << "Q3: " << um["Q3"] << '\n';
	cout << "Q4: " << um["Q4"] << '\n';
	cout << "AXIS: " << um["AXIS"] << '\n';

	return 0;
}