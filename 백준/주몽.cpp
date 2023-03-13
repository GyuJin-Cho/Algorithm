#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	for(int i=0;i<N;i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int start = 0;
	int end = v.size()-1;
	int sum = 0;
	int answer = 0;
	while(start<end)
	{
		if (v[start] + v[end] == M)
		{
			answer++;
			start++;
			end--;
		}
		else if(v[start]+v[end]>M)
		{
			end--;
		}
		else
		{
			start++;
		}
	}
	cout << answer;
	return 0;
}