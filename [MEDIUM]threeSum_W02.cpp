//https://leetcode.com/problems/3sum/submissions/1059365425/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l, r, sum;

        for (int i = 0; i < n-2; i++) {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i-1])
                continue;

            l = i + 1;
            r = n - 1;
            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else {
                    res.push_back({nums[i], nums[l++], nums[r--]});
                    while(l < r && nums[r] == nums[r+1]) r--;
                    while(l < r && nums[l] == nums[l-1]) l++;
                }      
            }
        }
        return res;
    }
};