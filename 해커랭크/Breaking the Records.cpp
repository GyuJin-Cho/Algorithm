#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	vector<int> scores(T);
	int Min = 10000000;
	int Max = -1;
	int MinCount = 0, MaxCount = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> scores[i];
		if (i == 0)
		{
			Min = scores[i];
			Max = scores[i];
		}
		if (Min > scores[i])
		{
			Min = scores[i];
			MinCount++;
		}
		else if (Max < scores[i])
		{
			Max = scores[i];
			MaxCount++;
		}
	}
	cout << MaxCount << " " << MinCount;
	return 0;
}