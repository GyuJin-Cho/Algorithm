#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size());
    stack<int> st;
    for(int i=numbers.size()-1;i>=0;i--)
    {
	    while(1)
	    {
		    if(st.empty())
		    {
                answer[i] = -1;
                break;
		    }
            if(st.top()>numbers[i])
            {
                answer[i] = st.top();
                break;
            }
            st.pop();
	    }
        st.push(numbers[i]);
    }

    return answer;
}

int main()
{
    vector<int> v = solution({ 2,3,3,5 });
    for (int i : v)
        cout << i <<' ';

    return 0;
}