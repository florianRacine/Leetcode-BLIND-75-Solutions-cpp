<h1> Valid Anagram </h1>

<h2> Problem </h2>

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

<h2> Sort </h2>

<h3> Solution </h3>

* if (word == sort(word)) -> return true
* if (word != sort(word)) -> return false

<h3> Complexity </h3>

* Time : O(nlog(n))
* Space : O(1)
 
 <h2> Hash map </h2>
 
 <h3> Solution </h3>

Check if for each letter word have the same number of occurencies.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(n)

<h3> Implementation </h3>
 
```cpp
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
```
