#include<iostream>

using namespace std;

int main()
{
	int k, q, l, v, n, p;
	cin >> k >> q >> l >> v >> n >> p;
	int cnt = 0;
	if(k>1)
	{
		while (k > 1)
		{
			k--;
			cnt--;
		}
		cout << cnt << " ";
	}
	else if (k < 1)
	{
		cout << 1<<" ";
	}
	else
	{
		cout << 0 << " ";
	}
	cnt = 0;
	if (q > 1)
	{
		while (q > 1)
		{
			q--;
			cnt--;
		}
		cout << cnt << " ";
	}
	else if(q < 1)
	{
		cout << 1<<" ";
	}
	else
	{
		cout << 0 << " ";
	}
	cnt = 0;
	if (l > 2)
	{
		while (l > 2)
		{
			l--;
			cnt--;
		}
		cout << cnt << " ";
	}
	else if (l < 2)
	{
		while (l < 2)
		{
			l++;
			cnt++;
		}
		cout << cnt << " ";
	}
	else
	{
		cout << 0 << " ";
	}
	cnt = 0;
	if (v > 2)
	{
		while (v > 2)
		{
			v--;
			cnt--;
		}
		cout << cnt << " ";
	}
	else if(v < 2)
	{
		while (v < 2)
		{
			v++;
			cnt++;
		}
		cout << cnt << " ";
	}
	else
	{
		cout << 0 << " ";
	}
	cnt = 0;
	if (n > 2)
	{
		while (n > 2)
		{
			n--;
			cnt--;
		}
		cout << cnt << " ";
	}
	else if(n < 2)
	{
		while (n < 2)
		{
			n++;
			cnt++;
		}
		cout << cnt << " ";
	}
	else
	{
		cout << 0 << " ";
	}
	cnt = 0;
	if (p > 8)
	{
		while (p > 8)
		{
			p--;
			cnt--;
		}
		cout << cnt << " ";
	}
	else if (p < 8)
	{
		while (p < 8)
		{
			p++;
			cnt++;
		}
		cout << cnt << " ";
	}
	else
	{
		cout << 0 << " ";
	}
	return 0;
}