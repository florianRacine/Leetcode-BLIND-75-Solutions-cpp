class Solution {
public:
    bool isPalindrome(string s) {
        int length = (int) s.size();
        string s_alphanumeric = "";
        for (int i = 0; i < length; i++) {
            if (('a' <= s[i]  && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) {
                s_alphanumeric += (s[i]);
            } else if ('A' <= s[i] && s[i] <= 'Z') {
                s_alphanumeric += (s[i] - 'A' + 'a');
            }
        }
        int n = (int) s_alphanumeric.size();
        for (int i = 0; i < n/2; i++) {
            if (s_alphanumeric[i] != s_alphanumeric[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
