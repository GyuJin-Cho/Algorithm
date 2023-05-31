#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int solution(int N, string s)
{
   

    int result = N + 1;
    int cnt = 0; 
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == 'L')
        {
            cnt++;
            if (cnt % 2 == 0)
            {
                result--;
            }
        }
    }

    if (cnt != 0)
        return result;
    else
        return N;

}

int main()
{
    int N;
    string str;

    cin >> N;
    cin >> str;
	cout << solution(N,str);

	return 0;
}