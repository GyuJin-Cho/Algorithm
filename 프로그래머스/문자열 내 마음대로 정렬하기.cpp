#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
int ncount;

using namespace std;
bool cmp(string a,string b)
{
   if(a[ncount]!=b[ncount])
   {
       return a[ncount] < b[ncount];
   }
   else
   {
       return a < b;
   }
}
vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;
    ncount = n;

    sort(strings.begin(), strings.end(), cmp);

    answer = strings;

    return answer;
}

int main()
{
    vector<string> strings = { "abce", "abcd", "cdx" };
    vector<string>a = solution(strings, 2);
    for(auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}