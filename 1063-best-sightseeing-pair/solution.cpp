class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, currMax = values[0];
        int n = values.size();
        for (int j=1; j<n; j++){
            ans = max(ans, currMax+values[j]-j);
            currMax = max(currMax, values[j]+j);
        }
        return ans;
    }
};
