#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list)
{
    string answer = "";

    for(int i=0;i<index_list.size();i++)
    {
        answer += my_string[index_list[i]];
    }

    return answer;
}

int main()
{
    vector<int> v = { 16, 6, 5, 3, 12, 14, 11, 11, 17, 12, 7 };
    string s = solution("cvsgiorszzzmrpaqpe", v);
    cout << s;

    return 0;
}