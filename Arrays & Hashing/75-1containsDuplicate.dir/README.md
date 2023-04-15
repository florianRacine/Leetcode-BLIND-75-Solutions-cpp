<h1> Contains Duplicate </h1>

<h2> Problem </h2>

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

<h2> Brute force solution </h2>

<h3> Solution </h3>

We can iterate through each pair of elements and check if they are equal.

* If two elements are equal, return true.
* If no elements are found to be equal, return false.

<h3> Complexity </h3>

* Time : O(n²)
* Space : O(1)

<h2> Sort solution </h2>

<h3> Solution </h3>

First, we sort the list. Then we iterate through the list and check if two adjacent elements are equal.

* If two adjacent elements are equal, return true.
* If no adjacent elements are found to be equal, return false.

<h3> Complexity </h3>

* Time : O(nlog(n))
* Space : O(1)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};
```

<h2> Hash map solution </h2>

<h3> Solution </h3>

We iterate through the list and add each element to a hash map. If an element has already been added to the hash map, we return true.
  
* If an element is found that has already been added to the hash map, return true.
* If no duplicates are found, return false.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(n)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < (int) nums.size(); i++) {
            if (mp[nums[i]] != 0) return true;
            mp[nums[i]]++;
        }
        return false;
    }
};
```
