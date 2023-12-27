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
#include <regex>

using namespace std;

int main()
{
	int T;
	cin >> T;
	regex re("(^[A-F]?A+F+C+[A-F]?$)");
	while (T--) 
	{
		string str;
		cin >> str;
		if (regex_match(str, re)) 
		{
			cout << "Infected!" << '\n';
		}
		else 
		{
			cout << "Good" << '\n';
		}
	}

	return 0;
}
