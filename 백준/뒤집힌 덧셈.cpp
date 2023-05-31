    #include<iostream>
    #include<algorithm>
    #include<stack>
    using namespace std;

    int main()
    {
        int N,M;
        cin>>N>>M;
        stack<char>s;
        string s1 = to_string(N);
        for(int i=0;i<s1.size();i++)
        {
            s.push(s1[i]);
        }
        string tmp="";
        while(!s.empty())
        {
            tmp+=s.top();
            s.pop();
        }
        int N1 = stoi(tmp);
        s1 = to_string(M);
        for(int i=0;i<s1.size();i++)
        {
            s.push(s1[i]);
        }
        tmp.clear();
        while(!s.empty())
        {
            tmp+=s.top();
            s.pop();
        }
        int M1 = stoi(tmp);
        
        s1 = to_string(N1+M1);
        for(int i=0;i<s1.size();i++)
        {
            s.push(s1[i]);
        }
        tmp.clear();
        while(!s.empty())
        {
            tmp+=s.top();
            s.pop();
        }
        
        int answer = stoi(tmp);
        cout<<answer;
        return 0;
    }
