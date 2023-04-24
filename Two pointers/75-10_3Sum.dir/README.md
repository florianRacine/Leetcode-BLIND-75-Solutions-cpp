<h1> 3 Sum </h1>

<h2> Solution </h2>

The given solution uses a two-pointer approach to find all the triplets in the input integer array nums that add up to zero. The solution follows the following steps:

* Sort the input array nums in non-decreasing order.
* For each unique number nums[i] in nums, use two pointers left and right to find all the pairs (nums[left], nums[right]) such that nums[i] + nums[left] + nums[right] = 0.
* If such a triplet is found, add it to the ans vector. If not, move the left or right pointer accordingly.

<h2> Complexity </h2>

* Time : O(n²)
* Space : O(n)

<h2> Implementation </h2>

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp1;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (mp1[nums[i]] == 0) {
                int left = i + 1, right = n - 1;
                while (left != right) {
                    if (nums[i] + nums[left] + nums[right] < 0) {
                        left ++;
                    } else if (nums[i] + nums[left] + nums[right] > 0) {
                        right --;
                    } else {
                        ans.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        while (nums[left-1] == nums[left] && left != right) {
                            left++;
                        }
                    }
                }
                mp1[nums[i]] = 1;
            }
        }
        return ans;
    }
};
```
