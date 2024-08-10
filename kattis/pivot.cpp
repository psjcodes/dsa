#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    vector<int> v(n), min_v(n), max_v(n);
    int min, max;
    cin >> v[0];
    
    max_v[0] = v[0];
    max = max_v[0];
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        if (v[i] > max) {
            max = v[i];
        }
        max_v[i] = max;
    }
    
    min_v[n - 1] = v[n - 1];
    min = min_v[n - 1];
    for (int j = n - 2; j >= 0; --j) {
        if (v[j] < min) min = v[j];
        min_v[j] = min;
    }
    
    int pivots = 0;
    for (int k = 0; k < n; ++k) {
        if (v[k] >= max_v[k] && v[k] <= min_v[k]) ++pivots;
    }
    
    cout << pivots;
    
    return 0;
}