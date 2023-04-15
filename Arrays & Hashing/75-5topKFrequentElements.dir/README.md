<h1> Top K Frequent Elements </h1>

<h2> Problem </h2>

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

<h2> Sort solution </h2>

<h3> Solution </h3>

* Count occurencies in a hash map.
* Sort by number of occurencies decreasingly.
* Take the first k number.

<h3> Complexity </h3>

* Time : O(nlog(n))
* Space : O(n)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;

    // Get frequency for each num
    unordered_map<int, int> mp; // unordered to use HASH map
    for (int i = 0; i < (int) nums.size(); i++) {
        mp[nums[i]] ++; // Key -> num ; Value -> frequency
    }

    // Sort by frequency
    vector<pair<int,int>> vec;
    for (auto it: mp) {
        vec.push_back({it.second, it.first}); // Frequency is put first in pair because sort will use the first element by default
    }
    sort(vec.rbegin(), vec.rend()); // Reverse sort so we can iterate frome left to right

    // Get the k most frequent integer
    for (int i = 0; i < k; i++) {
        ans.push_back(vec[i].second);
    }
    return ans;
    }
};
```
