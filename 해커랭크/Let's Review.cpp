#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int b;
    int count=0;
    string a[10];
    string Jacksu[10];
    string holsu[10];
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        cin >> a[i];
        for (int j = 0; j < a[i].length(); j++)
        {
            if (j % 2 == 0)
            {
                Jacksu[count] += a[i][j];
            }
            else
            {
                holsu[count] += a[i][j];
            }
        }
        count++;
    }
    for (int i = 0; i < b; i++)
    {
        cout << Jacksu[i] << " " << holsu[i] << endl;
    }
    return 0;
}
