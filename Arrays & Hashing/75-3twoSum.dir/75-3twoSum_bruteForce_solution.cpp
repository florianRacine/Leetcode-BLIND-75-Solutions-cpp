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
