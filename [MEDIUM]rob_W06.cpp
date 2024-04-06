//https://leetcode.com/problems/house-robber/submissions/1085252212/

class Solution {
public:
    int rob(vector<int>& nums) {
        int* f = new int[nums.size()+1];

        f[0] = 0;
        f[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
            f[i] = max(nums[i-1] + f[i-2], f[i-1]);

        return f[nums.size()];
    }
};