#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int x;
    cin >> x;
    
    int y = x;
    vector<int> digits;
    while (y != 0) {
        digits.push_back(y % 10);
        y /= 10;
    }
    sort(digits.begin(), digits.end());
    
    int minOfMax = 1000000;
    do {
        int z = 0;
        for (int i = 0; i < digits.size(); ++i) {
            z += digits[i] * pow(10, i);
        }
        if (z > x && z < minOfMax) minOfMax = z;
    } while (next_permutation(digits.begin(), digits.end()));
    
    if (minOfMax != 1000000) cout << minOfMax << endl;
    else cout << 0 << endl;
    
    return 0;
}