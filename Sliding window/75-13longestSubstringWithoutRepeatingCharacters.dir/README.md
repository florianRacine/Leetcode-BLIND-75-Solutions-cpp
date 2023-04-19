<h1> Longest Substring Without Repeating Characters </h1>

<h2> Problem </h2>

Given a string s, find the length of the longest substring without repeating characters.

<h2> Map solution </h2>

<h3> Solution </h3>

Right pointer move to the right at each iteration.
If the right pointer is on an element that is already in the current window, the left pointer moves to the right of the first occurrence of this element.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(n)

<h3> Implementation </h3>

```cpp
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
```
