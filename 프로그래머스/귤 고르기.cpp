#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;

    map<int, int> m;
    for(int i=0;i<tangerine.size();i++)
    {
        m[tangerine[i]]++;
    }

    vector<int> v;
    for(auto u : m)
    {
        v.push_back(u.second);
    }

    sort(v.begin(), v.end(), greater<int>());

    int cnt = 0;
    for(int i=0;i<v.size();i++)
    {
        if (cnt >= k)
            break;
        answer++;
        cnt += v[i];
    }

	return answer;
}

int main()
{
    cout << solution(6, { 1, 3, 2, 5, 4, 5, 2, 3 });

    return 0;
}