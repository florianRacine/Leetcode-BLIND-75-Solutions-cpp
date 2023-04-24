<h1> Longest Substring Without Repeating Characters </h1>

<h2> Problem </h2>

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

<h2> Map Solution </h2>

<h3> Solution </h3>

The approach uses a sliding window technique to find the length of the longest substring containing the same letter that can be obtained by changing at most k characters of the original string. We keep track of the frequency count of each character in the current window using an array of size 26. We maintain variables to keep track of the maximum frequency of any character in the current window, the left endpoint of the current window, and the length of the longest substring seen so far. For each character in the string, we update the frequency count, update the maximum frequency, slide the window to the right, and adjust the window by sliding it to the right until we have at most k characters that are not the character with maximum frequency.

<h3> Complexity </h3>

* Time : O(26n) = O(n)
* Space : O(n)

<h3> Implementation </h3>

```cpp
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
```

<h3> Nb </h3>

There is a tricky way to not iterate through each letters.
