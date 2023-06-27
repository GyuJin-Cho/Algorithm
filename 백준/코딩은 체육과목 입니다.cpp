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
	stack<string> s;
	s.push("int");
	for(int i=0;i<N;i=i+4)
	{
		s.push("long");
	}

	while(!s.empty())
	{
		cout << s.top()<<' ';
		s.pop();
	}

	return 0;
}