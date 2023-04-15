/*A = [a1, a2, ..., an]*/

/*Pref = [1, a1, a1*a2, ..., a1*a2*...*ai, ... , a1*a2*...*an-1]*/
/*Pref[i] = a1*a2*...*ai*/

/*Suf = [a2*...*an, a3*...*an, ... , an, 1]*/
/*Suf [i] = ai+1*ai+2*...*an*/


/*ans[i] = a1*a2*...*ai-1*ai+1* ...*an*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = (int) nums.size();
    vector<int> ans(n);
    vector<int> Pref(n), Suf(n);
    Pref[0] = 1;
    Suf[n-1] = 1;
    for (int i = 1; i < n; i++) {
        Pref[i] = Pref[i-1]*nums[i-1];
        Suf[n-i-1] = Suf[n-i]*nums[n-i];
    }
    for (int i = 0; i < n; i++) {
        ans[i] = Pref[i] * Suf[i];
    }
    return ans;
    }
};
