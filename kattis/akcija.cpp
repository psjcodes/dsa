#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    
    sort(prices.begin(), prices.end(), greater<>());
    
    int min_price = 0;
    for (int j = 0; j < prices.size(); ++j) {
        if (j % 3 != 2) min_price += prices[j];
    }
    
    cout << min_price;

    return 0;
}