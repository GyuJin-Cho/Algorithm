#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int>MineralList;                
int AllList[3][3] = { {1,1,1},{5,1,1},{25,5,1} }; 
vector<int>MineralsIntList;
int ListSize = 0;
int answer = 1250;

void DFS(vector<int>&picks, int location, int sum)
{
    int sumlist[3]{ 0, };
    int savepoint = 0;
    if(ListSize<=location||picks[0]+picks[1]+picks[2]==0)
    {
        answer = min(answer, sum);
        return;
    }

    for(int i=location;i<location+5;i++)
    {
	    if(i>=ListSize)
	    {
            savepoint = i;
            break;
	    }
        sumlist[0] += AllList[0][MineralsIntList[i]];
        sumlist[1] += AllList[1][MineralsIntList[i]];
        sumlist[2] += AllList[2][MineralsIntList[i]];

        savepoint = i;
    }

    for(int i=0;i<3;i++)
    {
	    if(picks[i]!=0)
	    {
            picks[i] -= 1;
            DFS(picks, savepoint + 1, sum + sumlist[i]);
            picks[i] += 1;
	    }
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    MineralList["diamond"] = 0;
    MineralList["iron"] = 1;
    MineralList["stone"] = 2;

    ListSize = minerals.size();

    for(string i : minerals)
    {
        MineralsIntList.push_back(MineralList[i]);
    }
    DFS(picks, 0, 0);
    return answer;
}

int main()
{
    cout << solution({ 1,3,2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" });


    return 0;
}