class Solution {
/*
bruh moment

each edge has to contain the center node

so we just check if the first node of first edge
is present in the second edge

if it is then the center is that first node
otherwise it has to be the second node of the first edge
*/

public:
    int findCenter(vector<vector<int>>& e) {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};