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
	int N;
	cin >> N;
	int num=0;
	int Min=0;
	int Young=0;
	float mul = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		Young = Young + ((num / 30 + 1)*10);
		Min = Min + ((num / 60 + 1)*(15));
	}
	if (Min < Young)
	{
		cout << "M " << Min;
	}
	else if (Young < Min)
	{
		cout << "Y " << Young;
	}
	else
	{
		cout << "Y M " << Min;
	}


	return 0;
}