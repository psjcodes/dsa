#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    vector<int> sides(4);
    cin >> sides[0] >> sides[1] >> sides[2] >> sides[3];
    
    sort(sides.begin(), sides.end());
    cout << sides[2] * sides[0];

    return 0;
}