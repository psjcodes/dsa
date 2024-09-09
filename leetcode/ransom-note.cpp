class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> char_counts(26);

        for (char c : magazine) {
            char_counts[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (--char_counts[c - 'a'] < 0) return false;
        }

        return true;
    }
};