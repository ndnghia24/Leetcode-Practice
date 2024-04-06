// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1073363235/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r && nums[l] > nums[r]) {
            int m = (l + r) / 2;

            if (nums[m] >= nums[l])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};