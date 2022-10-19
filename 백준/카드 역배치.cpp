#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> arr(20);
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		int start, end;
		cin >> start >> end;

		reverse(arr.begin()+start-1, arr.begin()+end);
	}
	for (auto i : arr)
	{
		cout << i << " ";
	}
	return 0;
}