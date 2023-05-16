#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int p1, int p2)
{
	return p1 > p2;
}

int main()
{
	vector<int> S(4);
	vector<int> So(4);
	for(int i=0;i<4;i++)
	{
		cin >> S[i];
	}
	for(int i=0;i<2;i++)
	{
		cin >> So[i];
	}
	sort(S.begin(), S.end(),cmp);
	sort(So.begin(), So.end(),cmp);

	int sum = 0;
	for (int i = 0; i < 3; i++)
		sum += S[i];
	sum += So[0];
	cout << sum;


	return 0;
}