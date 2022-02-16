class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int max=0;
        int n=prices.size();
        
        for (int i=1; i<n; i++)
        {
            if (prices[i]<=min)
            {
                min=prices[i];
            }
            else
            {
                if (max<prices[i]-min)
                {
                    max=prices[i]-min;
                }
            }
        }
        return max;
    }
};
