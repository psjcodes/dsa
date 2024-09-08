/*
p straightforward
ternary :D
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string res;
        int n = min(word1.size(), word2.size());
        for (int i = 0; i < n; ++i) {
            res.push_back(word1[i]); res.push_back(word2[i]);
        }
        string longWord = word1.size() > word2.size() ? word1 : word2;
        res += longWord.substr(n);

        return res;
    }
};