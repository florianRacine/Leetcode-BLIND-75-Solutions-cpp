class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Define a sorted list of sorted words -> strs_sorted
        vector<string> strs_sorted((int) strs.size());
        for (int i = 0; i < (int) strs.size(); i++) {
            strs_sorted[i] = strs[i];
            sort(strs_sorted[i].begin(), strs_sorted[i].end());
        }
        sort(strs_sorted.begin(), strs_sorted.end());

        // Iterate in strs_sorted only one time for each word.
        set<string> visitedWord;
        vector<vector<string>> ans;
        for (int i = 0; i < (int) strs_sorted.size(); i++) {
            if (visitedWord.count(strs_sorted[i]) == 0) {
                vector<string> group; // list of anagram like strs_sorted[i]
                for (int j = 0; j < (int) strs.size(); j++) {
                    string word = strs[j];
                    sort(word.begin(), word.end());
                    if (word == strs_sorted[i]) {
                        group.push_back(strs[j]);
                    }
                }
                ans.push_back(group);
            }
            visitedWord.insert(strs_sorted[i]);
        }
        return ans;
    }
};
