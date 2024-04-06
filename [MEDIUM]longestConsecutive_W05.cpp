//https://leetcode.com/problems/longest-consecutive-sequence/submissions/1057200058/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        
        if (n == 0)
            return 0;

        for (int num : nums) {
            set.insert(num);
        }

        int maxStreak = 0;
        int countStreak;
        int curNum;
        
        for (int num : set) {
            countStreak = 1;
            curNum = num;
            
            if (set.find(curNum-1) != set.end())
                continue;

            while(set.find(++curNum) != set.end()) {
                countStreak++;
            }
            maxStreak = max(maxStreak, countStreak);
        }

        return maxStreak;
    }
};