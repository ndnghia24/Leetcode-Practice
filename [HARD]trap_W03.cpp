//https://leetcode.com/problems/trapping-rain-water/submissions/1062921282/

class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;
        int sum = 0;
        int lowerBar;

        while (l < r) {
            lowerBar = min(h[l], h[r]);
            while (l < r && h[l] <= lowerBar) {
                sum += max(lowerBar - h[++l], 0);
            }
            lowerBar = min(h[l], h[r]);
            while (l < r && h[r] <= lowerBar) {
                sum += max(lowerBar - h[--r], 0);
            }
        }
        cout << sum;
        return sum;
    }
};