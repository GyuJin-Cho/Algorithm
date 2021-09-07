#include<iostream>

using namespace std;

bool check(int x1, int v1, int x2, int v2)
{
	while (true)
	{
		if (v1<=v2)
			return false;
		x1 += v1;
		x2 += v2;
		if (x1 == x2)
			return true;
		if (x1 > x2)
			return false;
	}
}

int main()
{
	int x1, v1;
	int x2, v2;
	cin >> x1 >> v1>>x2>>v2;
	if (check(x1, v1, x2, v2))
		cout << "YES";
	else
		cout << "NO";
	
	
	return 0;
}