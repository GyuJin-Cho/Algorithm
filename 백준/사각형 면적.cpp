#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>

using namespace std;

int main() {
    int N, C, cy, cx;
    cin >> N >> C;
    cy = N;
	cx = N;
    int y, x;
    while (C--) 
    {
        cin >> y >> x;
        if (y > cy || x > cx) 
            continue;
        int ny = y;
        int nx = cx;
    	int w = y * cx;
        if (w < cy * x) 
        {
            ny = cy;
        	nx = x;
        }
        cy = ny;
    	cx = nx;
    }
    cout << cy * cx;
}