#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int solution(string numbers)
{
    int answer = 0;
    set<int> s;
    sort(numbers.begin(), numbers.end());
    do
    {
        string temp = "";
        for(int i=0;i<numbers.size();i++)
        {
            temp += numbers[i];
            s.insert(stoi(temp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    int max = *s.rbegin();
    vector<bool> check(4000000000, true);
    check[0] = false;
    check[1] = false;

    for(int i=2;i*i<=max;i++)
    {
	    if(check[i])
            for(int j=i*i;j<=max+1;j+=i)
            {
                check[j] = false;
            }
    }

    for(auto iter = s.begin();iter!=s.end();iter++)
    {
        if (check[*iter])
            answer++;
    }
    return answer;
}

int main()
{
    string a = "9999999";
    cout << solution(a);
    return 0;
}