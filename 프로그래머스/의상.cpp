#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;


using namespace std;

int solution(vector<vector<string>> clothes)
{
    int ans = 1;
    unordered_map<string, int> um;
    for (const auto& cloth : clothes)
    {
        um[cloth[1]]++;
    }
    for (const auto& count : um)
    {
        ans *= (count.second + 1);
    }
    return ans - 1;
}