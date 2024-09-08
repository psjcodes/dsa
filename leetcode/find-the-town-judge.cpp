/*
n people labeled 1-n
one of them is the town judge

if town judge exists:
    they trust nobody
    everybody trusts them
    only one 

# of people that trust them (indeg)
minus
# of people they trust (outdeg)
== n - 1 --> everyone trusts them (except themselves ofc)

in other words outdeg should be 0
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1, 0);    // keeps track of the difference indeg - outdeg
        for (auto& pair : trust) {
            count[pair[1]]++;   // someone trusts pair[1] (indeg)
            count[pair[0]]--;   // pair[0] trusts someone (outdeg)
        }
        for (int i = 1; i <= n; ++i) {
            if (count[i] == n - 1) return i;
        }
        return -1;
    }
};