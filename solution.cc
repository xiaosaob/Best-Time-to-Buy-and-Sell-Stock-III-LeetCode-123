// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<int> firstTradeMaxP(n, 0);
        int maxP = 0;
        int lowest = prices[0];
        for(int i = 1; i < n; ++i) {
            if(prices[i]-lowest > maxP)
                maxP = prices[i]-lowest;
            else if(prices[i] < lowest)
                lowest = prices[i];
            firstTradeMaxP[i] = maxP;
        }
        int finalMaxP = 0;
        maxP = 0;
        int highest = prices[n-1];
        for(int i = n-1; i >= 0; --i) {
            if(highest-prices[i] > maxP)
                maxP = highest-prices[i];
            else if(prices[i] > highest)
                highest = prices[i];
            finalMaxP = max(finalMaxP, maxP+firstTradeMaxP[i]);
        }
        return finalMaxP;
    }
};
