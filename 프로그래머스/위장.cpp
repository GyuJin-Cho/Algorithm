#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;


using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> m;
    for(auto cloth:clothes)
    {
        m[cloth[1]] += 1;
    }
    for(auto iter=m.begin();iter!=m.end();iter++)
    {
        answer =answer* (iter->second + 1);
    }
    return answer-1;
}
int main()
{
    vector<vector<string>> v = { {"yellowhat", "headgear"},
    	                           {"bluesunglasses", "eyewear"},
    	                           {"green_turban", "headgear"},
									{"redsunglasses","eyewear"}};
    cout << solution(v);
	return 0;
}