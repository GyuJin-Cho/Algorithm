#include <iostream>
#include <string>
#include <vector>

using namespace std;
int y, x;
bool North(const vector<string>& park, const vector<string>& routes,int go)
{
    if (y - go < 0)
        return false;
    int sy = y;
    int sx = x;
    while(go--)
    {
        if (park[--sy][sx] == 'X')
            return false;
    }
    return true;
}

bool South(const vector<string>& park, const vector<string>& routes, int go)
{
    if (y + go >= (int)(park[0].size()))
        return false;
    int sy = y;
    int sx = x;
    while (go--)
    {
        if (park[++sy][sx] == 'X')
            return false;
    }
    return true;
}

bool West(const vector<string>& park, const vector<string>& routes, int go)
{
    if (x - go < 0)
        return false;
    int sy = y;
    int sx = x;
    while (go--)
    {
        if (park[sy][--sx] == 'X')
            return false;
    }
    return true;
}

bool East(const vector<string>& park, const vector<string>& routes, int go)
{
    if (x + go >= (int)(park[0].size()))
        return false;
    int sy = y;
    int sx = x;
    while (go--)
    {
        if (park[sy][++sx] == 'X')
            return false;
    }
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    
    for(int i=0;i<park.size();i++)
    {
	    for(int j=0;j<park[i].length();j++)
	    {
		    if(park[i][j]=='S')
		    {
                y = i;
                x = j;
		    }
	    }
    }

    for(int i=0;i<routes.size();i++)
    {
        char p = routes[i][0];
        int go = routes[i][2]-48;

        if(p=='N')
        {
            if (North(park, routes, go))
                y -= go;
        }
        else if(p=='S')
        {
            if (South(park, routes, go))
                y += go;
        }
        else if (p == 'W')
        {
            if (West(park, routes, go))
                x -= go;
        }
        else if (p == 'E')
        {
            if (East(park, routes, go))
                x += go;
        }
    }

    answer.push_back(y);
    answer.push_back(x);
    return answer;
}

int main()
{
    vector<string> park = { "OSO","OOO","OXO","OOO" };
    vector<string> r = { "E 2","S 3","W 1" };
    vector<int>ans = solution(park, r);
    for (int i : ans)
        cout << i << ' ';

    return 0;
}