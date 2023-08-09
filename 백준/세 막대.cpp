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

int main()
{
	int TriAngle[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> TriAngle[i];
	}
	sort(TriAngle, TriAngle + 3);

	if (TriAngle[2] < TriAngle[0] + TriAngle[1])
	{
		cout << TriAngle[0] + TriAngle[1] + TriAngle[2];
	}
	else
	{
		cout << (TriAngle[0] + TriAngle[1]) * 2 - 1;
	}

	return 0;
}