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
#include<cstring>
#include <sstream>

using namespace std;
string zfill(string s, int cnt)
{
	while(s.length()<cnt)
	{
		s = '0' + s;
	}
	return s;
}
int main()
{
	string ipv6;
	cin >> ipv6;
	
	string part;
	istringstream sin(ipv6);
	vector<string> parts;
	while(getline(sin,part,':'))
	{
		parts.push_back(part);
	}

	if(count(parts.begin(),parts.end(),"")>1)
	{
		parts.erase(find(parts.begin(), parts.end(), ""));
	}
	if(parts.size()<8)
	{
		vector<string>::iterator it = find(parts.begin(), parts.end(), "");
		it = parts.erase(it);
		parts.insert(it, 8 - (int)parts.size(), "0");
	}
	for(int i=0;i<parts.size();i++)
	{
		cout << zfill(parts[i], 4);
		if (i + 1 < parts.size())
			cout << ':';
	}
	return 0;
}