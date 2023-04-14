class Solution {
public:
    bool isAnagram(string s, string t) {
        if ((int)s.size() != (int)t.size()) {
            return false;
        } else {
            unordered_map <char, int> mp1;
            unordered_map <char, int> mp2;
            vector<char> vec;
            for (int i = 0; i < (int) s.size(); i++) {
                if (mp1[s[i]] == 0) vec.push_back(s[i]);
                mp1[s[i]]++;
                mp2[t[i]]++;
            }
            for (int i = 0; i < (int) vec.size(); i++) {
                if (mp1[vec[i]] != mp2[vec[i]]) return false;
            }
            return true;
        }
    }
};
