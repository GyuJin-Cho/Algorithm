#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;
    unordered_map<string, int> name_to_idx;
    name_to_idx["code"] = 0;
    name_to_idx["date"] = 1;
    name_to_idx["maximum"] = 2;
    name_to_idx["remain"] = 3;

    auto it = remove_if(data.begin(), data.end(), [idx = name_to_idx[ext], val_ext](const auto& row) 
    {
        return !(row[idx] < val_ext);
    });
    data.erase(it, data.end());

    sort(data.begin(), data.end(), [idx = name_to_idx[sort_by]](const auto& row1, const auto& row2)
    {
        return row1[idx] < row2[idx];
    });
    return data;
}

int main()
{
    vector<vector<int>> data = { {1, 20300104, 100, 80},{2, 20300804, 847, 37},{3, 20300401, 10, 8} };
    vector<vector<int>> ans = solution(data, "data", 20300501, "remain");

    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}