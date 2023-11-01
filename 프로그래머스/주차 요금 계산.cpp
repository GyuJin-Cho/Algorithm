#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
int BasicMin = 0; // 기본 분
int BasicPCost = 0; //기본 금액
int BasicPlusMin = 0; //추과 분
int BasicCost = 0; // 추가 금액
constexpr int MAX = 1439; // 23:59
vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;

    BasicMin = fees[0];
    BasicPCost = fees[1];
    BasicPlusMin = fees[2];
    BasicCost = fees[3];
    unordered_map<string, int> gates;
    unordered_map<string, int> ans;
    for(int i=0;i<records.size();i++)
    {
        int hour = stoi(records[i].substr(0, 2));
        int Min = stoi(records[i].substr(3, 2));

        string carnum = records[i].substr(6, 4);
        string state = records[i].substr(11, 3);
        int totalMin = (hour * 60) + Min;
        if(state =="IN")
        {
            gates[carnum] = totalMin;
        }
        else if(state=="OUT")
        {
            ans[carnum] += (totalMin - gates[carnum]);
            gates[carnum] = -1;
        }
    }
    for(auto i : gates)
    {
	    if(i.second!=-1)
	    {
            ans[i.first] += (MAX -i.second);
	    }
    }
    vector<pair<string, int>> answertemp;
    for(auto i : ans)
    {
	    if(i.second>BasicMin)
	    {
            int ce = ceil((double)(i.second - BasicMin) / (double)BasicPlusMin);
            int tmp1 = ce * BasicCost;
            int tmp2 = BasicPCost + tmp1;
            answertemp.push_back({ i.first,tmp2 });
	    }
        else
        {
            answertemp.push_back({ i.first,BasicPCost });
        }
    }
    sort(answertemp.begin(), answertemp.end());

    for(int i=0;i<answertemp.size();i++)
    {
        answer.push_back(answertemp[i].second);
    }

    return answer;
}

int main()
{
    vector<int> v = solution({ 1, 461, 1, 10 }, { "00:00 1234 IN" });
    for (auto i : v)
        cout << i << ' ';
    return 0;
}