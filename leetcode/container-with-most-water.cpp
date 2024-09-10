/*
calc the curr area
compare with max
move pointer that has lower height (greedy)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;
        int currArea = 0;
        while (l < r) {
            currArea = min(height[l], height[r]) * (r - l);
            maxArea = max(maxArea, currArea);
            height[l] < height[r] ? ++l : --r;
        }
        return maxArea;
    }
};