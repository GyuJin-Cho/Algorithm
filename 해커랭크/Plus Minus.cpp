#include<iostream>

using namespace std;
int arr[101];
int main()
{
	float answer;
	int T;
	cin >> T;
	float zero = 0;
	float negative = 0;
	float positive = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
			zero++;
		else if (arr[i] > 0)
			positive++;
		else if (arr[i] < 0)
			negative++;
	}
	printf("%.6f\n", positive / T);
	printf("%.6f\n", negative / T);
	printf("%.6f\n", zero / T);

}