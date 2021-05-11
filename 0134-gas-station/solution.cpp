class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0;
        int pref=0;
        int curr=0;
        int n=gas.size();
        for (int i=0; i<n; i++)
        {
            curr+=gas[i]-cost[i];
            if (curr<0)
            {
                ans=i+1;
                pref=pref+curr;
                curr=0;
            }
        }
        if (pref+curr>=0)
            return ans;
        return -1;
    }
};
