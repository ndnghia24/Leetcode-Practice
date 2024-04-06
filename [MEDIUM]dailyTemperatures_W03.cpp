// https://leetcode.com/problems/daily-temperatures/submissions/1064006833/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();

        vector<int> res(size);
        int stackArr[size];
        int n = 1; 
        stackArr[0] = 0;

        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i-1] < temperatures[i]) {
                while (n > 0 && temperatures[stackArr[n-1]] < temperatures[i]) {
                    res[stackArr[n-1]] = i - stackArr[n-1];
                    n--;
                }
            }
            stackArr[n++] = i;
        }
        return res;
    }
};