class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;

    // Get frequency for each num
    unordered_map<int, int> mp; // unordered to use HASH map
    for (int i = 0; i < (int) nums.size(); i++) {
        mp[nums[i]] ++; // Key -> num ; Value -> frequency
    }

    // Sort by frequency
    vector<pair<int,int>> vec;
    for (auto it: mp) {
        vec.push_back({it.second, it.first}); // Frequency is put first in pair because sort will use the first element by default
    }
    sort(vec.rbegin(), vec.rend()); // Reverse sort so we can iterate frome left to right

    // Get the k most frequent integer
    for (int i = 0; i < k; i++) {
        ans.push_back(vec[i].second);
    }
    return ans;
    }
};
