/*
first pass:
    set res[i] = res[i - 1] * nums[i - 1]
    if nums = [a, b, c] then

    [1, 0, 0] -> [1, a, 0], -> [1, a, ab] -> done


second pass:
    starting from the back, r = 1
    set res[i] *= r
        r *= nums[i]

    [1, a, ab], r = 1
    -> [1, a, ab], r = c
    -> [1, ac, ab], r = bc
    -> [bc, ac, ab], r = abc
    -> done

tc: O(n), sc: O(1) (output arr doesnt count)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = 1;

        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        
        return res;
    }
};