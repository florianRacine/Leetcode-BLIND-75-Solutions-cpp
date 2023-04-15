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
