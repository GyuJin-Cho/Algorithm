#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l)
{
    vector<int> answer;

    for(int i=0;i<intStrs.size();i++)
    {
		string tmp = "";
	    for(int j=s;j<s+l;j++)
	    {
			tmp += intStrs[i][j];
	    }
		if(stoi(tmp)>k)
		{
			answer.push_back(stoi(tmp));
		}
    }

    return answer;
}

int main()
{
    vector<string> v = { "0123456789","9876543210","9999999999999" };
	vector<int> ans = solution(v, 50000, 5, 5);
	for (auto i : ans)
		cout << i << ' ';

    return 0;
}