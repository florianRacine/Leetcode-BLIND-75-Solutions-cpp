<h1> Two Sum </h1>

<h2> Problem </h2>

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

<h2> Brute force solution </h2>

<h3> Solution </h3>

We can iterate through each pair of elements and check if there sum is equal to the target.

<h3> Complexity </h3>

* Time : O(n²)
* Space : O(1)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec(2);
        for (int i = 0; i < (int) nums.size(); i++) {
            for (int j = i + 1; j < (int) nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    vec[0] = i;
                    vec[1] = j;
                    return vec;
                }
            }
        }
        return vec;
    }
};
```

<h2> Sort solution </h2>

<h3> Solution </h3>

First, we sort the list. 

* p_left = 0, p_right = n
* if (nums[p_left] + nums[p_right] < target) -> p_left++
* if (nums[p_left] + nums[p_right] > target) -> p_right--
* if (nums[p_left] + nums[p_right] > target) -> return {nums[p_left] , nums[p_right]}

<h3> Complexity </h3>

* Time : O(nlog(n))
* Space : O(1)

<h2> Map solution </h2>

<h3> Solution </h3>

We can iterate through the list.
* Add the current number in the map.
* Check if (target - nums[i]) is in the map.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(n)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec(2);
        unordered_map<int, int> mp;
        for (int i = 0; i < (int) nums.size(); i++) {
            if (mp[target - nums[i]] > 0) {
                vec[0] = mp[target - nums[i]]-1;
                vec[1] = i;
                return vec;
            }
            mp[nums[i]] = i+1;
        }
        return vec;
    }
};
```
