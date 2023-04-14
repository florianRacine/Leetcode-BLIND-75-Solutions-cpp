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
