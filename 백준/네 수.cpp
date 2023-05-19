#include<iostream>
#include<string>

using namespace std;

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	string ab=to_string(A)+to_string(B);
	string cd = to_string(C) + to_string(D);

	unsigned long long AB = stoll(ab);
	unsigned long long CD = stoll(cd);
	cout << AB + CD;

	return 0;
}