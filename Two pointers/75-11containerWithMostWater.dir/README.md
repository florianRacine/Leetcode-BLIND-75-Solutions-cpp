<h1> Containter with most water </h1>

<h2> Brute Force Solution </h2>

<h3> Solution </h3>

The brute force solution would be to loop through every possible pair of lines and calculate the water contained by that container. We then keep track of the maximum amount of water seen so far. 

<h3> Complexity </h3>

* Time : O(n²)
* Space : O(1)

<h3> Implementation </h3>

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int n = (int) height.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int currRes = min(height[i], height[j]) * abs(i - j);
                if (currRes > max) {
                    max = currRes;
                }
            }
        }
        return max;
    }
};
```

<h2> Left/Right pointer solution </h2>

<h3> Solution </h3>

A better solution would be to use two pointers to keep track of the maximum area seen so far. We initialize two pointers, one at the start and one at the end of the array. We then calculate the area between these two lines and keep track of the maximum area seen so far. We then move the pointer with the smaller height inwards and repeat the process.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(1)

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
