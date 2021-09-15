#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;

bool DFS(string Cur,vector<vector<string>> Ticket, int Count,vector<bool> & visit)
{
    answer.push_back(Cur);
    if (Count == Ticket.size())
        return true;

    for(int i=0;i<Ticket.size();i++)
    {
	    if(Ticket[i][0]==Cur&&visit[i]==false)
	    {
            visit[i] = true;
            bool T = DFS(Ticket[i][1],Ticket, Count + 1, visit);
            if (T)
                return true;
            visit[i] = false;
	    }
    }
    answer.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets)
{
    vector<bool> visit(tickets.size(),false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, 0, visit);

    return answer;
}

int main()
{
    vector<vector<string>> a = { {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"}};
    vector<string> answer = solution(a);
    return 0;
}