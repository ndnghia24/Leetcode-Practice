// https://leetcode.com/problems/valid-parentheses/submissions/1062883691/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> map;
        map.insert({')', '('});
        map.insert({']', '['});
        map.insert({'}', '{'});
        
        for(char ch : s) {
            if (map.count(ch) == 0) {
                st.push(ch);
            } 
            else {
                if (!st.empty() && st.top() == map[ch])
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty())
            return true;

        return false;
    }
};