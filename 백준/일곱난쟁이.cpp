#include <iostream>
#include <algorithm>
#define MAX 9 
using namespace std;
int main() {
    int a[MAX], acc = 0;
    for (int i = 0; i < MAX; i++) {
        cin >> a[i];
        acc += a[i];
    }
    sort(a, a + MAX);
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = i + 1; j < MAX; j++) {
            if (acc - a[i] - a[j] == 100) {
                for (int k = 0; k < MAX; k++) {
                    if (a[k] != a[i] && a[k] != a[j])
                        cout << a[k] << "\n";
                }
                exit(0);
            }
        }
    }
}