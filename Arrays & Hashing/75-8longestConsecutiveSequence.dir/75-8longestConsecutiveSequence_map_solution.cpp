class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = (int) nums.size();
        unordered_map <int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = 1;
        }
        int maxLength = 0;
        int currentLength;
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]-1] == 0) { // Beginning of a sequence
                currentLength = 0;
                int j = nums[i];
                while (mp[j] == 1) {
                    j++;
                    currentLength ++;
                }
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
            }
        }
        return maxLength;
    }
};
