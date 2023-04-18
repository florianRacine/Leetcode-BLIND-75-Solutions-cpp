class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int) prices.size();
        int a = prices[0], b = -1;
        int m = 0;
        for(int i = 1; i < n; i ++) {
            if (prices[i] < a) {
                a = prices[i];
                b = -1;
            } else if (prices[i] > b) {
                b = prices[i];
                m = max(b-a,m);
            }
        }
        return m;
    }
};
