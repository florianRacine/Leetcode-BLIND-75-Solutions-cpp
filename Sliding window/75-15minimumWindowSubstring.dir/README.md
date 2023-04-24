<h1> Minimum Window Substring </h1>

<h2> Solution </h2>

The problem asks to find the minimum window in s that contains all the characters of t. One way to approach this problem is to use a sliding window technique. We can maintain a window that starts from the beginning of s and moves forward until it contains all the characters of t. Once we have such a window, we can try to shrink it by moving the window's start pointer forward while still keeping all the characters of t in the window. This will give us the minimum window.

1. Check if s is shorter than t. If it is, there is no possible solution, and we return an empty string.
2. Create a frequency map of characters in t.
3. Initialize count, start, min_length, and min_start to 0.
4. Traverse the string s using the end pointer.
5. If the current character in s is present in the frequency map, increment the count
6. Decrement the frequency of the current character in the frequency map.
7. If the count equals the length of t, it means we have found a window that contains all characters of t. Now we try to shrink the window by moving the start pointer forward until the window still contains all the characters of t.
8. If the length of the current window is smaller than the minimum length so far, update the minimum length and the minimum start.
9. Increment the frequency of the character at the start pointer and decrement the count.
10. Return the minimum window or an empty string if no window exists.

<h3> Complexity </h3>

* Time : O(N), where N is the length of the string s.
* Space : O(M), where M is the length of the string t. 

<h3> Implementation </h3>

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<char,int> map;
        for(int i=0;i<t.size();i++){
            map[t[i]]++;
        }
        int count=0,start=0,min_length = INT_MAX, min_start = 0;
        for(int end=0; end<s.size(); end++){
            if(map[s[end]]>0){
                count++;
            }
            map[s[end]]--; 
            if(count == t.length()) { 
                while(start < end && map[s[start]] < 0){
                    map[s[start]]++, start++;
                } 
                if(min_length > end-start){
                    min_length = end-(min_start=start)+1; 
                }
                map[s[start++]]++; 
                count--;
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length);
    }
};
```
