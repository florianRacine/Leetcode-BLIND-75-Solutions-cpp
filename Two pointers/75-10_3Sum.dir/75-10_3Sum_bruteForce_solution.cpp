class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (int) nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if( nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> curr_ans = {nums[i], nums[j], nums[k]};
                        sort(curr_ans.begin(), curr_ans.end());
                        bool cond = false;
                        for (int l = 0; l < (int) ans.size(); l++) {
                            if (curr_ans == ans[l]) {
                                cond = true;
                            }
                        }
                        if (!cond) {
                            ans.push_back(curr_ans);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

