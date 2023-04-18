class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,bool> mp;
        int n = (int) s.size();
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            while (mp[s[r]]) {
                mp[s[l]] = false;
                l++;
            }
            mp[s[r]] = true;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
