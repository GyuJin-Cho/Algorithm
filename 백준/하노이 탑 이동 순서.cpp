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

void Hanoi(int start, int mid, int end, int num)
{
	if (num == 1)
	{
		cout << start << ' ' << end << '\n';
	}
	else
	{
		Hanoi(start, end, mid, num - 1);
		cout << start << ' ' << end << '\n';
		Hanoi(mid, start, end, num - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';
	Hanoi(1, 2, 3, n);

	return 0;
}