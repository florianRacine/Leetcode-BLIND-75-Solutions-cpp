<h1> Best Time To Buy And Sell Stock </h1>

<h2> Problem </h2>

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

<h2> Brute Force </h2>

<h3> Solution </h3>

For each price we consider it as a buy price and we find the highest price to sell.
We return the maximum value between the buy price and the sell price.

<h3> Complexity </h3>

* Time : O(n²)
* Space : O(1)

<h2> Two pointers </h2>

<h3> Solution </h3>

For each iteration we consider the lowest current element as a buy price and we search the highest price to sell.

<h3> Complexity </h3>

* Time : O(n)
* Space : O(1)

<h3> Implementation </h3>

```cpp
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
```
