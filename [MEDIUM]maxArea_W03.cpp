//https://leetcode.com/problems/container-with-most-water/submissions/1059417628/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; 
        int r = height.size() - 1;
        int maxArea = 0;

        while (l < r) {
            if(height[l] > height[r]) {
                maxArea = max(maxArea, height[r] * (r-l));
                r--;
            }
            else {
                maxArea = max(maxArea, height[l] * (r-l));
                l++;
            }
        }
        return maxArea;
    }
};