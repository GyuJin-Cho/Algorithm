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
int Arr[26][2] = 
{
	{1, 2}, {5, 3}, {3, 3}, {3, 2}, {3, 1}, {4, 2}, {5, 2},
	{6, 2}, {8, 1}, {7, 2}, {8, 2}, {9, 2}, {7, 3}, {6, 3}, {9, 1}, {10, 1},
	{1, 1}, {4, 1}, {2, 2}, {5, 1}, {7, 1}, {4, 3}, {2, 1}, {2, 3}, {6, 1},
	{1, 3}
};

set<int> Lft;

void Init()
{
	Lft.insert('q' - 'a');
	Lft.insert('w' - 'a');
	Lft.insert('e' - 'a');
	Lft.insert('r' - 'a');
	Lft.insert('t' - 'a');
	Lft.insert('a' - 'a');
	Lft.insert('s' - 'a');
	Lft.insert('d' - 'a');
	Lft.insert('f' - 'a');
	Lft.insert('g' - 'a');
	Lft.insert('z' - 'a');
	Lft.insert('x' - 'a');
	Lft.insert('c' - 'a');
	Lft.insert('v' - 'a');
}

int main()
{
	Init();
	char l, r;
	cin >> l >> r;

	string str;
	cin >> str;

	int ans = 0;

	for(const char& i : str)
	{
		if(Lft.find(i-'a')!=Lft.end())
		{
			ans += (abs(Arr[l - 'a'][0] - Arr[i - 'a'][0]) + abs(abs(Arr[l - 'a'][1] - Arr[i - 'a'][1])));
			ans++;
			l = i;
		}
		else
		{
			ans += (abs(Arr[r - 'a'][0] - Arr[i - 'a'][0]) + abs(abs(Arr[r - 'a'][1] - Arr[i - 'a'][1])));
			ans++;
			r = i;
		}
	}
	cout << ans;
	return 0;
}