class Solution {
public:
    int characterReplacement(string s, int k) {
        int st[26] = {0};
        int n = (int) s.size();
        int m = 1; // Occurence of the char that occure the most in the current window.
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            st[(int) s[r] - 'A']++;
            m = 0;
            for (int i = 0; i < 26; i++) {
                if (m < st[i]) {
                    m = st[i];
                }
            }
            while (k < (r - l + 1) - m) {
                st[(int) s[l] - 'A'] --;
                l++;
                m = 0;
                for (int i = 0; i < 26; i++) {
                    if (m < st[i]) {
                        m = st[i];
                    }
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
