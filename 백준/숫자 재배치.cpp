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
#include<cstring>

using namespace std;

int main()
{
	string a;
	int b;
	cin >> a >> b;
	int answer = -1;
	sort(a.begin(), a.end());
	do
	{
		int c = stoi(a);
		if(a[0]!='0'&&c<b)
		{
			answer = max(answer, c);
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << answer;
	return 0;
}