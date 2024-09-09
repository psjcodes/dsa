/*
that min() is so troll lmao
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> nums = {
            {'b', 0},
            {'a', 0},
            {'l', 0},
            {'o', 0},
            {'n', 0}
        };

        for (char c : text) {
            if (nums.contains(c)) {
                ++nums[c];
            }
        }

        return min({ nums['b'], nums['a'], nums['l']/2, nums['o']/2, nums['n'] });
    }
};