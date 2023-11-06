#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> ans, int now)
{
	for(int i=0;i<ans.size();i++)
	{
        if ((ans[i] & now) == ans[i])
            return false;
	}
    return true;
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;

    int r = relation.size();
    int c = relation[0].size();
    vector<int> ans;

    for(int i=1;i<(1<<c);i++)
    {
	    set<string>s;
        for(int j=0;j<r;j++)
        {
            string tmp = "";

            for(int k=0;k<c;k++)
            {
                if (i & (1 << k))
                    tmp += relation[j][k];
            }
            s.insert(tmp);
        }
        if (s.size() == r && check(ans, i))
            ans.push_back(i);
    }
    
    return ans.size();
}

int main()
{
    vector<vector<string>> re = 
    {
    	{"100", "ryan", "music", "2"},
        {"200", "apeach", "math", "2"},
    	{"300", "tube", "computer", "3"},
        {"400", "con", "computer", "4"},
    	{"500", "muzi", "music", "3"},
        {"600", "apeach", "music", "2"}
    };
    cout << solution(re);
    return 0;
}