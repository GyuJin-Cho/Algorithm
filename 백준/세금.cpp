#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	cout << N * 78 / 100 << ' ' << N * 8 / 10 + (N * 2 / 10) * 78 / 100;

	return 0;
}