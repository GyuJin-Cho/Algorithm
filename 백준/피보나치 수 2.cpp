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
int main()
{
	unsigned long long N;
    cin >> N;
    unsigned long long result[91];

    result[0] = 0;
    result[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        result[i] = result[i - 1] + result[i - 2];
    }

    cout << result[N];
    return 0;
}


