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
#include<cstring>

using namespace std;
int n=3;
vector<vector<int>> magic = {
    {8, 1, 6, 3, 5, 7, 4, 9, 2},
    {6, 1, 8, 7, 5, 3, 2, 9, 4},
    {4, 3, 8, 9, 5, 1, 2, 7, 6},
    {2, 7, 6, 9, 5, 1, 4, 3, 8},
    {2, 9, 4, 7, 5, 3, 6, 1, 8},
    {4, 9, 2, 3, 5, 7, 8, 1, 6},
    {6, 7, 2, 1, 5, 9, 8, 3, 4},
    {8, 3, 4, 1, 5, 9, 6, 7, 2}
};
int diff(const vector<int>&a, const vector<int>&d)
{
    int answer = 0;
    for(int i=0;i<n*n;i++)
    {
        int tmp = a[i] - d[i];
        tmp = abs(tmp);
        answer += tmp;
    }
    return answer;
}

int main()
{
    vector<int>a(n * n);
    for (int i = 0; i < n * n; i++)
        cin >> a[i];

    int answer = -1;
    for(const auto&d : magic)
    {
        int cost = diff(a, d);
        if (answer==-1||answer > cost)
            answer = cost;
    }
    cout << answer;
	return 0;
}