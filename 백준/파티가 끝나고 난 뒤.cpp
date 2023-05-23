#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main()
{
	int L, P;
	cin >> L >> P;

	int area = L * P;
	vector<int> ans;
	int human;
	for(int i=0;i<5;i++)
	{
		cin >> human;
		ans.push_back(human - area);
	}
	for(int i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}