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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    string name;
    unordered_map<string, int> umap;
    for (int i = 0; i < N; i++) 
    {
        cin >> name;
        umap[name]++;
    }
    for (int i = 0; i < N - 1; i++)
    {
        cin >> name;
        umap[name]--;
    }
    for (auto it = umap.begin(); it != umap.end(); it++) 
    {
        if (it->second != 0)
            cout << it->first;
    }

	return 0;
}