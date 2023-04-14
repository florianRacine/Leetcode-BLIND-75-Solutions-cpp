class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < (int) strs.size(); i++) {
        string tmp = strs[i];
        sort(tmp.begin(), tmp.end());
        mp[tmp].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto it: mp) {
        ans.push_back(it.second);
    }
    return ans;
    }
};
