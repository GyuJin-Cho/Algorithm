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
	int sum = 0;
	int num;

	for(int i=0;i<5;i++)
	{
		cin >> num;
		sum += num;
	}
	cout << sum;
	return 0;
}