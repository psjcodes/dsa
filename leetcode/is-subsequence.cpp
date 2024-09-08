/*
for each char in t
check if curr char from s is there
if there is a match, advance s char
use iterator?

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == "") return true;
        auto it = s.begin();
        for (const auto& c : t) {
            if (*it == c) ++it;
            if (it == s.end()) return true;
        }
        return false;
    }
};