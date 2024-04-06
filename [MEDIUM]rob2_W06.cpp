// https://leetcode.com/problems/house-robber-ii/submissions/1085265929/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[nums.size()-1];
            
        int* f = new int[nums.size()+1];
        int max_arr1 = 0;
        int max_arr2 = 0;

        f[0] = 0;
        f[1] = nums[0];
        for (int i = 2; i < nums.size(); i++)
            f[i] = max(nums[i-1] + f[i-2], f[i-1]);

        max_arr1 = f[nums.size()-1];

        f[1] = 0;
        f[2] = nums[1];
        for (int i = 3; i <= nums.size(); i++)
            f[i] = max(nums[i-1] + f[i-2], f[i-1]);

        max_arr2 = f[nums.size()];

        return max(max_arr1, max_arr2);
    }
};