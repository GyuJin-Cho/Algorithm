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

    string str1, str2;
    cin >> str1 >> str2;

    int cnt = 0;
    int cnt1 = 0;

    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == 'a') {
            cnt++;
        }
    }

    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] == 'a') {
            cnt1++;
        }
    }
    if (cnt >= cnt1 || str1.length() == str2.length()) {    // keypoint
        cout << "go";
    }
    else {
        cout << "no";
    }
}
