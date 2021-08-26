#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int A[100001];
void Solution(int m,int n)
{
	int start = 0;
	int end = n - 1;
	int mid;
	while (end >= start)
	{
		mid = (start + end) / 2;
		if (A[mid] == m)
		{
			cout << 1 << '\n';
			return;
		}
		else if (A[mid] > m)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << 0 << '\n';
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	int n;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		A[i]=m;
	}
	cin >> m;
	sort(A,A+n);
	for (int i = 0;i < m; i++)
	{
		cin >> temp;
		Solution(temp,n);
	}

	
	return 0;
}