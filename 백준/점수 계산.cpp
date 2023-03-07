#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	vector<pair<int, int>> v;

	int num;

	for(int i=0;i<8;i++)
	{
		cin >> num;
		v.push_back({ num,i + 1 });
	}

	sort(v.begin(), v.end(),greater<>());

	int result = 0;

	for(int i=0;i<5;i++)
	{
		result += v[i].first;
	}

	cout << result << '\n';
	vector<int> indexs;
	for(int i=0;i<5;i++)
	{
		indexs.push_back(v[i].second);
	}

	sort(indexs.begin(), indexs.end());

	for (int i = 0; i < 5; i++)
	{
		cout << indexs[i] << " ";
	}


	return 0;
}