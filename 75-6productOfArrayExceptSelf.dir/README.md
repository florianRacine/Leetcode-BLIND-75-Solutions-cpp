<h1>Product of Array Except Self</h1>

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

<h2>Problem</h2>

<h2>Brute Force</h2>

<h3>Solution</h3>

Solved using Array(Two Nested Loop). Brute Force Approach.

<h3>Complexity</h3>

* Time = O(n²)
* Space = O(1)

<h3>Implementation</h3>

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }
};
```

<h2></h2>

<h3>Solution</h3>

Solved using Dynamic Programming Approach(tabulation).

<h3>Complexity</h3>

* Time = O(n)
* Space = O(n)

<h3>Implementation</h3>
  
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);
        vector<int> right_Product(n);
        left_Product[0] = 1;
        for(int i=1; i<n; i++){
            left_Product[i] = left_Product[i-1] * nums[i-1];
        }
        right_Product[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            right_Product[i] = right_Product[i+1] * nums[i+1];
        }
        for(int i=0; i<n; i++){
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};
```

<h2></h2>

<h3>Solution</h3>

Solved using Dynamic Programming Approach(Space Optimization). Optimized Approach.

<h3>Complexity</h3>

* Time = O(n)
* Space = O(1)

<h3>Implementation</h3>
  
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};
```
