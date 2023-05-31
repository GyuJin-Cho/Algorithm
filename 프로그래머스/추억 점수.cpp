#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;
    unordered_map<string, int>um;
    for(int i=0;i<name.size();i++)
    {
        um[name[i]] = yearning[i];
    }

    

    for(int i=0;i<photo.size();i++)
    {
        int sum = 0;
	    for(int j=0;j<photo[i].size();j++)
	    {
            sum += um[photo[i][j]];
	    }
        answer.push_back(sum);
    }


    return answer;
}

int main()
{
    vector<string> name = { "may", "kein", "kain", "radi" };
    vector<int> yearning = { 5,10,1,3 };
    vector<vector<string>> photo = { {"may", "kein", "kain", "radi"}
    	, {"may", "kein", "brin", "deny"}
    	, {"kon", "kain", "may", "coni"} };

    vector<int> ans = solution(name, yearning, photo);
    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}