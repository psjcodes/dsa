/*
find str with shortest len?
then for each char
check all other strs
break when doesnt match
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        string shortest = strs[0];
        for (const auto& str : strs) {
            shortest = shortest.size() < str.size() ? shortest : str;
        }

        for (int i = 0; i < shortest.size(); ++i) {
            for (const auto& str : strs) {
                if (shortest[i] != str[i]) return str.substr(0, i);
            }
        }
        
        return shortest;
    }
};