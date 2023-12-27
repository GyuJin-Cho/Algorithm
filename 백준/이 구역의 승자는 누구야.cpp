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

int Alpha [26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };

int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for(int i=0;i<s.length();i++)
	{
		sum += Alpha[s[i] - 'A'];
		if (sum >= 10)
			sum %= 10;
	}
	if (sum % 2 == 1)
		cout << "I'm a winner!\n";
	else
		cout << "You're the winner?\n";
	return 0;
}