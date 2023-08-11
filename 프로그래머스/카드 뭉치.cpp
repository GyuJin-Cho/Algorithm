#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_sameword(string s1, string s2)
{
    if (s1.size() != s2.size()) 
        return false;
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i]) 
            return false;
    return true;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < goal.size(); i++)
    {
        if (idx1 < cards1.size() && is_sameword(cards1[idx1], goal[i]))
            idx1++;
        else if (idx2 < cards2.size() && is_sameword(cards2[idx2], goal[i]))
            idx2++;
        else 
            return "No";
    }
    return "Yes";
}
int main()
{
    vector<string> cards1 = { "i", "drink", "water" };
    vector<string> cards2 = { "want", "to" };
    vector<string> goal = { "i", "want", "to", "drink", "water" };

    cout << solution(cards1,cards2,goal);

    return 0;
}