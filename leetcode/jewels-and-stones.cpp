/*
chuck all the jewels into a set
for each stone check if it is in set of jewels
*/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jwls(jewels.begin(), jewels.end());
        int num = 0;
        for (const auto& s : stones) {
            if (jwls.contains(s)) ++num;
        }
        return num;
    }
};