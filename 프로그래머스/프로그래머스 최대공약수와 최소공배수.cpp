#include <string>
#include <vector>
#include<iostream>
using namespace std;

int gcd(int n,int b)
{
	if (b == 0)
		return n;
	else
	{
		return gcd(b, n % b);
	}
}

vector<int> solution(int n, int m)
{
    vector<int> answer;
	answer.push_back(gcd(n, m));
	answer.push_back((n*m)/gcd(n, m));
    return answer;
}

int main()
{
	vector<int> a = solution(2, 5);
	for(auto i:a)
	{
		cout << i << " ";
	}
	return 0;
}