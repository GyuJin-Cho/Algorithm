#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, string control)
{

    for(int i=0;i<control.size();i++)
    {
	    if(control[i]=='w')
	    {
            n++;
	    }
        else if(control[i]=='s')
        {
            n--;
        }
        else if(control[i]=='d')
        {
            n += 10;
        }
        else
        {
            n -= 10;
        }
    }

    return n;
}
int main()
{
    cout << solution(0, "wsdawsdassw");

    return 0;
}