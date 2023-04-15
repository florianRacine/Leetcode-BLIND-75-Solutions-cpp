<h1> Group Anagrams </h1>

<h2> Problem </h2>

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

<h2> Map solution </h2>

<h3> Solution </h3>

We can iterate through the list of word.
* map[sort(word)].push_back(word)

We can iterate through the map and appaend all the group of anagram.

<h3> Complexity </h3>

* Time : O(n*w*log(w)) avec w = word.size
* Space : O(n)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < (int) strs.size(); i++) {
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        mp[tmp].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto it: mp) {
        ans.push_back(it.second);
    }
    return ans;
    }
};
```
