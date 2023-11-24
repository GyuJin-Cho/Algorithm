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
	while(T--)
	{
		int y, k;
		int a=0, b=0;
		for(int i=0;i<9;i++)
		{
			cin >> y >> k;
			a += y;
			b += k;
		}
		if (a > b)
			cout << "Yonsei" << '\n';
		else if (a < b)
			cout << "Korea" << '\n';
		else
			cout << "Draw" << '\n';
	}
	
	return 0;
}