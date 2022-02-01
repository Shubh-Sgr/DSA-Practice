class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int n=prices.size();
        int local_min;
        int local_max;
        int profit=0;
        
        while (i<n)
        {
            while (i<n-1 && prices[i]>=prices[i+1])
            {
                i++;
            }
            if (i==n-1)
            {
                break;
            }
            local_min=prices[i];
            while (i<n-1 && prices[i]<=prices[i+1])
            {
                i++;
            }
            local_max=prices[i];
            profit+=local_max-local_min;
            if (i==n-1)
            {
                break;
            }
        }
        return profit;
    }
};
