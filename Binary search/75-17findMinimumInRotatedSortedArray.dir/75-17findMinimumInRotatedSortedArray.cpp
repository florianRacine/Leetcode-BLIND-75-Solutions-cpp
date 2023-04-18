class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return min(nums[0], nums[1]);
        int left = 0, right = n-1, m = (left+right)/2; 
        while (true) {
            if (m == 0 || nums[m-1] > nums[m]) {
                return nums[m];
            } else if (nums[m] > nums[right]) {
                left = m + 1;
            } else if (nums[m] < nums[right]) {
                right = m;
            }
            m = (left+right)/2;
        }
    }
};
