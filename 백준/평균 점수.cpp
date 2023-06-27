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
	int sum = 0;
	for(int i=0;i<5;i++)
	{
		cin >> N;
		if(N>=40)
		{
			sum += N;
			continue;
		}
		sum += 40;
	}
	cout << sum / 5;
	return 0;
}