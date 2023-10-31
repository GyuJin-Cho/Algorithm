#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int solution(vector<int> cards)
{
    vector<bool> visit(cards.size() + 1, false);
    vector<int> ans;

    for(int i=0;i<cards.size();i++)
    {
        int cur = cards[i];
    	int cnt = 0;
        while(!visit[cur])
        {
            visit[cur] = true;
            cur = cards[cur - 1];
            cnt++;
        }
        if (cnt)
            ans.push_back(cnt);
    }

    sort(ans.begin(), ans.end(),greater<int>());
    return ans.size() > 1 ?( ans[0] * ans[1]) : 0;
}

int main()
{
    cout << solution({ 8,6,3,7,2,5,1,4 });

    return 0;
}