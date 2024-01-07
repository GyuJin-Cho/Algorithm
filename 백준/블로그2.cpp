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
	int n;
	cin >> n;
	int sum = 0;
	int size = 0;
	int r = 0, b = 0;
	char tmp;
	char arr[500001] = { 0,};
	int pt = 0;
	for(int i=0;i<n;i++)
	{
		cin >> tmp;
		if(i==0)
		{
			arr[pt] = tmp;
			size++;
			pt++;
		}
		else if(i!=0&&arr[pt-1]!=tmp)
		{
			arr[pt] = tmp;
			size++;
			pt++;
		}

	}

	for(int i=0;i<size-1;i++)
	{
		if (arr[i] == 'R')
			r++;
		else if (arr[i] == 'B')
			b++;
	}

	if (r < b)
		sum += 1 + b;
	else
		sum += 1 + r;

	cout << sum;

	return 0;
}