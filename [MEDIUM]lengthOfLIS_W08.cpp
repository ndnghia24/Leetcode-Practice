// https://leetcode.com/problems/longest-increasing-subsequence/submissions/1090529899/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {  
        int n = nums.size();
        int* f = new int[n];

        f[0] = 1;
        int res = 1;
        
        for (int i = 1; i < n; i++)
        {
            f[i] = 1;
            for (int j = i-1; j >= 0; j--)
            {
                if (nums[i] <= nums[j])
                    continue;
                else
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }

        return res;
    }
};