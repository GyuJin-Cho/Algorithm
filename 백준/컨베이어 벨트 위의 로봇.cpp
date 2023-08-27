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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(2 * n);
	for(int i=0;i<2*n;i++)
	{
		cin >> a[i];
	}
	vector<bool> box(2 * n, false);
	int zero = 0;
	for(int t=1;;t++)
	{
		rotate(a.rbegin(), a.rbegin() + 1, a.rend());
		rotate(box.rbegin(), box.rbegin() + 1, box.rend());
		if(box[n-1])
		{
			box[n - 1] = false;
		}
		for(int i=n-2;i>=0;i--)
		{
			if(box[i])
			{
				if(!box[i+1]&&a[i+1]>0)
				{
					box[i + 1] = true;
					box[i] = false;
					a[i + 1] --;
					if(a[i+1]==0)
					{
						zero++;
					}
				}
			}
		}
		if(box[n-1])
		{
			box[n - 1] = false;
		}
		if(a[0]>0)
		{
			box[0] = true;
			a[0]--;
			if(a[0]==0)
			{
				zero++;
			}
		}
		if(zero>=k)
		{
			cout << t;
			break;
		}
	}


	return 0;
}