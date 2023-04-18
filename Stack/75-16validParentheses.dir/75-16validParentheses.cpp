class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        int n = (int) s.size();
        stack<char> ord;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                ord.push(s[i]);
            } else if (s[i] == ']') {
                if ((int) ord.size() == 0 || ord.top() != '[') {
                    ans = false;
                    break;
                } else {
                    ord.pop();
                }
            } else if (s[i] == ')') {
                if ((int) ord.size() == 0 || ord.top() != '(') {
                    ans = false;
                    break;
                } else {
                    ord.pop();
                }
            } else if (s[i] == '}') {
                if ((int) ord.size() == 0 || ord.top() != '{') {
                    ans = false;
                    break;
                } else {
                    ord.pop();
                }
            }
        }
        if ((int) ord.size() > 0) ans = false;
        return ans;
    }
};
