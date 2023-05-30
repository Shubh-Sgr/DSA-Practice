class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0){
            return 0;
        }
        int min = prices[0];
        int profit=0;
        for (int i=0; i<n; i++){
            if (min>prices[i])
            {
                min=prices[i];
            }
            else if (min<prices[i] && profit<prices[i]-min){
                profit=prices[i]-min;
            }
        }
        return profit;
    }
};
