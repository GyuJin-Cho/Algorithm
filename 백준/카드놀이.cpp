#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int SumA = 0;
	int SumB = 0;
	vector<int> A(10);
	vector<int> B(10);
	for (int i = 0; i < 10; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> B[i];
	}
	char finalwin = 'D';

	for (int i = 0; i < 10; i++)
	{
		if (A[i] > B[i])
		{
			SumA += 3;
			finalwin = 'A';
		}
		else if (A[i] < B[i])
		{
			SumB += 3;
			finalwin = 'B';
		}
		else
		{
			SumA += 1;
			SumB += 1;
		}
	}

	if (SumA > SumB)
	{
		cout << SumA << ' ' << SumB << '\n';
		cout << 'A';
	}
	else if (SumA < SumB)
	{
		cout << SumA << ' ' << SumB << '\n';
		cout << 'B';
	}
	else
	{
		if(finalwin=='A')
		{
			cout << SumA << ' ' << SumB << '\n';
			cout << 'A';
		}
		else if(finalwin=='B')
		{
			cout << SumA << ' ' << SumB << '\n';
			cout << 'B';
		}
		else
		{
			cout << SumA << ' ' << SumB << '\n';
			cout << 'D';
		}
	}
	return 0;
}