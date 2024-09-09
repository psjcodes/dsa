class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int minOccur = nums.size() / 2;
        unordered_map<int, int> occur;
        for (auto num : nums) {
            if (++occur[num] > minOccur) return num;
        }
        return -1;
    }
};