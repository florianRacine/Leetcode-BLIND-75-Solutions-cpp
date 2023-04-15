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
