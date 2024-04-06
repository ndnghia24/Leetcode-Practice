//https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1063011563/

class Solution {
public:
    bool isOperator(string c) {
        if (c == "+") return true;
        else if (c == "-") return true;
        else if (c == "*") return true;
        else if (c == "/") return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (!isOperator(tokens[i]))
                st.push(stoi(tokens[i]));
            else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                if (tokens[i] == "+") st.push(num2 + num1);
                else if (tokens[i] == "-") st.push(num2 - num1);
                else if (tokens[i] == "*") st.push(num2 * num1);
                else if (tokens[i] == "/") st.push(num2 / num1);
            }
        }
        return st.top();
    }
};