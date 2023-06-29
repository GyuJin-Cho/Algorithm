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
	vector<int> students(N);
	for(int i=0;i<N;i++)
	{
		cin >> students[i];
	}
	long long b, c;
	cin >> b >> c;
	long long ans = 0;
	for(int i=0;i<students.size();i++)
	{
		int k = 1;
		if (students[i] > b) 
		{
			k += (students[i] - b) / c;
			if ((students[i] - b) % c > 0)
				k += 1;
		}
		ans += k;
	}
	cout << ans;

	return 0;
}