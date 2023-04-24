<h1> Valide Palindrome </h1>

<h2> Problem </h2> 

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

<h2> Pointer Left/Right Solution with extra memory</h2>

The given solution takes a string s as input and checks if it is a palindrome or not. The solution follows the following steps:

* Convert all uppercase letters into lowercase letters and remove all non-alphanumeric characters from the string.
* Compare the characters from the start and end of the string until the middle of the string is reached. If any pair of characters don't match, the string is not a palindrome.

<h2> Complexity </h2>

* Time : O(n), where n is the length of the input string s.
* Space : O(n)

<h2> Implementation </h2>

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int length = (int) s.size();
        string s_alphanumeric = "";
        for (int i = 0; i < length; i++) {
            if (('a' <= s[i]  && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) {
                s_alphanumeric += (s[i]);
            } else if ('A' <= s[i] && s[i] <= 'Z') {
                s_alphanumeric += (s[i] - 'A' + 'a');
            }
        }
        int n = (int) s_alphanumeric.size();
        for (int i = 0; i < n/2; i++) {
            if (s_alphanumeric[i] != s_alphanumeric[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
```

<h2> Pointer Left/Right Solution without extra memory </h2>

The given solution takes a string s as input and checks if it is a palindrome or not. The solution follows the following steps:

* Compare the characters from the start and end of the string until the middle of the string is reached. If any pair of characters don't match, the string is not a palindrome. If a character is not an alphanumerical character we skip it.

<h2> Complexity </h2>

* Time : O(n), where n is the length of the input string s.
* Space : O(1)

<h2> Implementation </h2>

```cpp
class Solution {
public:
    bool isAlphanumeric(char ch)    {
        if(ch >= 'a' && ch <= 'z')   return true;
        if(ch >= 'A' && ch <= 'Z')   return true;
        if(ch >= '0' && ch <= '9')  return true;
        return false;
    }

    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i < j)    {
            if( !isAlphanumeric(s[i]) ) i++;  
            else if( !isAlphanumeric(s[j]) ) j--;
            else if(tolower(s[i]) != tolower(s[j]))   return false;
            else    i++, j--;
        }
        return true;
    }
};
```
