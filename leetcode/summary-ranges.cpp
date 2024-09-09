/*
for each num
if prev upper + 1 equal to curr 
else make ranges, set upper and lower 
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return {to_string(nums[0])};

        vector<string> ranges;
        int l = nums[0];
        int u = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (u + 1 == nums[i]) ++u;
            else {
                if (l == u) ranges.push_back(to_string(l));
                else ranges.push_back(to_string(l) + "->" + to_string(u));
                l = u = nums[i];
            }
        }
        l == u ? ranges.push_back(to_string(l)) : ranges.push_back(to_string(l) + "->" + to_string(u));
        
        return ranges;
    }
};