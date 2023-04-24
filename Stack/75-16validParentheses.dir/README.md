<h1> Valid Parentheses </h1>

<h2> Stack solution </h2>

<h3> Solution </h3>

The given problem can be solved using a stack data structure. We can iterate over the characters of the string and push the opening brackets into the stack. Whenever we encounter a closing bracket, we check if the top element of the stack is the corresponding opening bracket. If it is, we pop the opening bracket from the stack, else we return false. Finally, we check if the stack is empty or not. If it is, then the string is valid, else it is invalid.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(n)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int) height.size();
        int left = 0, right = n - 1;
        vector<int> area;
        while (right - left >= 1) {
            area.push_back(min(height[left], height[right]) * (right - left));
            if (height[left] > height[right]) {
                right --;
            } else if(height[left] < height[right]) {
                left ++;
            } else {
                left ++;
                // or right --;
            }
        }
        int max = 0;
        for (int i = 0; i < n - 1; i++) {
            if (area[i] > max) {
                max = area[i];
            }
        }
        
        return max;
    }
};
```
