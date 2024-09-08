/*
keep track of min price
compute curr price - min price 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxPnl = 0;

        for (const auto& price : prices) {
            minPrice = min(minPrice, price);
            maxPnl = max(maxPnl, price - minPrice);
        }

        return maxPnl;
    }
};