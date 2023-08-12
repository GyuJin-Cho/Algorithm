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
#define PI 3.1415926535897932
int main()
{
	double r;
	cin >> r;
	printf("%.6f\n%.6f", r * r * PI, 2 * r * r);
	return 0;
}