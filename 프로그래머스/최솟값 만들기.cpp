#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), cmp);

	for(int i=0;i<A.size();i++)
	{
		answer += A[i] * B[i];
	}
	return answer;
}

int main()
{
	vector<int> A = { 1,4,2 };
	vector<int> B = { 5,4,4 };
	cout << solution(A, B);
	return 0;
}