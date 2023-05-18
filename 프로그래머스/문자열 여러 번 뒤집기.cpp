#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries)
{
    for(int i=0;i<queries.size();i++)
    {
        reverse(my_string.begin() + queries[i][0], my_string.begin() + queries[i][1] + 1);
    }

    return my_string;
}

int main()
{
    vector<vector<int>> qu = { {2,3},{0,7},{5,9},{6,10} };
    cout << solution("rermgorpsam", qu);

    return 0;
}