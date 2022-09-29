#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long num;
	vector<long long> SortingV;
	vector<long long> OriginalV;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		SortingV.push_back(num);
		OriginalV.push_back(num);
	}
	sort(SortingV.begin(), SortingV.end());
	SortingV.erase(unique(SortingV.begin(), SortingV.end()), SortingV.end());

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(SortingV.begin(), SortingV.end(), OriginalV[i]) - SortingV.begin() << " ";
	}

	return 0;
}