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
vector<string> nums =
{
"###...#.###.###.#.#.###.###.###.###.###",
"#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
"#.#...#.###.###.###.###.###...#.###.###",
"#.#...#.#.....#...#...#.#.#...#.#.#...#",
"###...#.###.###...#.###.###...#.###.###"
};
bool possible(vector<string>& a, int x, int y) 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (nums[i][4 * y + j] == '.' && a[i][4 * x + j] == '#') 
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{

    int n;
    cin >> n;
    vector<string> a(5);
    for (int i = 0; i < 5; i++) 
    {
        cin >> a[i];
    }
    vector<vector<int>> candidate(n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            if (possible(a, i, j)) 
            {
                candidate[i].push_back(j);
            }
        }
    }
    long long total = 1;
    for (int i = 0; i < n; i++) 
    {
        total *= (int)candidate[i].size();
    }
    if (total == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) 
    {
        long long cur = 0;
        for (int x : candidate[i]) 
        {
            cur += x;
        }
        sum = sum * 10 + cur * (total / (int)candidate[i].size());
    }
    printf("%f", ((double)sum / total));
    
    return 0;
	return 0;
}