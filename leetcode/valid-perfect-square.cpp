class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        long int l = 0;
        long int r = num;
        long int m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (m * m == num) return true;
            if (m * m < num) l = m + 1;
            else r = m - 1;
        }
        return (m * m == num);
    }
};