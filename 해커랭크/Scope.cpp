#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximumDifference;

    Difference(vector<int> a)
    {
        this->elements = a;
    }

    void computeDifference()
    {
        int max = -1;
        int ab;
        for (int i = 0; i < elements.size(); i++)
        {
            for (int j = 0; j < elements.size(); j++)
            {
                ab = elements[i] - elements[j];
                if (ab <= 0)
                {
                    ab = ab * -1;
                    if (max < ab)
                    {
                        max = ab;
                    }
                }

            }
        }
        maximumDifference = max;
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}