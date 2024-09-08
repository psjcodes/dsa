/*
compute abs val
compare to abs of curr closest
but also check if +ve or -ve
*/

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        for (const auto& num : nums) {
            if (abs(num) < abs(closest)
                || (abs(num) == abs(closest) && num > closest))
            {
                closest = num;
            }
        }
        return closest;
    }

    // solution i saw that uses custom comparator
    /*
    int findClosestNumber(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
        }
    }
    */
};