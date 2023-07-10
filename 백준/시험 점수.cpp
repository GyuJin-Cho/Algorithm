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
	int MinGuk=0;
	int ManSe=0;
	int num;
	for(int i=0;i<4;i++)
	{
		cin >> num;
		MinGuk += num;
	}
	for(int i=0;i<4;i++)
	{
		cin >> num;
		ManSe += num;
	}

	if(MinGuk>=ManSe)
	{
		cout << MinGuk;
	}
	else if(MinGuk<ManSe)
	{
		cout << ManSe;
	}
	return 0;
}