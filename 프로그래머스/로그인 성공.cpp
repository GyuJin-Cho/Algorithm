#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    string answer = "fail";

    map<string, string> m;

    for(int i=0;i<db.size();i++)
    {
        m[db[i][0]] = db[i][1];
    }

    for(auto i : m)
    {
	    if(i.first==id_pw[0])
	    {
		    if(i.second==id_pw[1])
		    {
                answer = "login";
                break;
		    }
            else
            {
                answer = "wrong pw";
            }
	    }
    }

    return answer;
}

int main()
{
    vector<string> id_pw = { "rabbit04", "98761" };
    vector<vector<string>> db ={{"jaja11", "98761"},{"krong0313", "29440"},{"rabbit00", "111333"}};
    cout << solution(id_pw, db);

    return 0;
}