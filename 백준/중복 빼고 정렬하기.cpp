#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<int> s;
	int N;
	cin >> N;
	int Num;
	for(int i=0;i<N;i++)
	{
		cin >> Num;
		s.insert(Num);
	}

	for(auto i : s)
	{
		cout << i << " ";
	}
}