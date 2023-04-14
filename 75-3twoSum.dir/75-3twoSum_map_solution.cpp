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
