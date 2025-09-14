#include <iostream>
using namespace std;

int solution(int n, int w, int num)
{
    int row = (num - 1) / w;
    int col = (num - 1) % w;

    if (row % 2 == 1)
    {
        col = w - 1 - col;
    }

    int count = 1;

    int r = row + 1;
    while (r * w < n)
    { 
        int start = r * w + 1;
        int target;
        if (r % 2 == 0)
        {
            target = start + col;
        }
        else
        {
            target = start + (w - 1 - col);
        }
        if (target <= n)
        {   
            count++;
        }
        r++;
    }

    return count;
}

int main() {
    cout << solution(22, 6, 2) << endl;
    cout << solution(13, 3, 6) << endl;
    return 0;
}