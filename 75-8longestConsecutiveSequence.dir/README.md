<h1> Longest Consecute Sequence </h1>

<h2> Problem </h2>

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

<h2> Hash map approach </h2>

<h3> Solution </h3>

* We add every element to a hash map.
* We iterate through elements that has no left neighbor.
  * We iterate through each of there neighbor to find the length of the sequence.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(n)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = (int) nums.size();
        unordered_map <int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = 1;
        }
        int maxLength = 0;
        int currentLength;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]-1] == 0) { // Beginning of a sequence
                currentLength = 0;
                int j = nums[i];
                while (mp[j] == 1) {
                    j++;
                    currentLength ++;
                }
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
            }
        }
        return maxLength;
    }
};
```
