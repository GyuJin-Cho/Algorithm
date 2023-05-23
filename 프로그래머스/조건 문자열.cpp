#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m)
{
    if(ineq=="<"&&eq=="=")
    {
        if (n <= m)
            return 1;
        else
            return 0;
    }
    else if(ineq=="<"&&eq=="!")
    {
        if (n < m)
            return 1;
        else
            return 0;
    }
    else if(ineq==">"&&eq=="=")
    {
        if (n >= m)
            return 1;
        else
            return 0;
    }
    else if(ineq==">"&&eq=="!")
    {
        if (n > n)
            return 1;
        else
            return 0;
    }
}

int main()
{
    cout << solution("<", "=", 20, 50);

    return 0;
}