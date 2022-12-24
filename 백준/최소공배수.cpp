#include<iostream>

using namespace  std;

int gcd(int a, int b)
{
	if(a%b==0)
	{
		return b;
	}
	else
	{
		return gcd(b, a % b);
	}

}

int main()
{
	int N;
	int a, b;
	int lod;

	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;

		lod = (a * b) / (gcd(a, b));
		cout << lod << '\n';
	}

	return 0;
}