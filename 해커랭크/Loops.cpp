#include<iostream>

using namespace std;

int main()
{
	int answer = 0;
	cin >> answer;

	for (int i = 1; i <= 10; i++)
	{
		cout << answer<<" x " << i << " = " << answer * i << endl;
	}
	return 0;
}