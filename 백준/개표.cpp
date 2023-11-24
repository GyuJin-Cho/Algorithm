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
	unordered_map<char, int>um;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		char a;
		cin >> a;
		um[a]++;
	}
	int ansnum = um['A'];
	char ans = 'A';

	if (um['B'] == ansnum)
		cout << "Tie";

	else if (um['B'] > ansnum)
		cout << 'B';
	else
		cout << 'A';
	return 0;
}