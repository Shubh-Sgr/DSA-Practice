class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxVal[n];
        int ans = 0;
        sort(events.begin(),events.end());
        maxVal[n-1] = events[n-1][2];
        for (int i=n-2; i>=0; i--){
            maxVal[i] = max(maxVal[i+1],events[i][2]);
        }
        for (int i=0; i<n; i++){
            ans = max(ans, events[i][2]);
            int low = i+1, high = n-1;
            int pos = n;
            while (low<=high){
                int mid = low + (high-low)/2;
                if (events[mid][0]>events[i][1]){
                    pos = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            if (pos<n){
                ans = max(ans, events[i][2]+maxVal[pos]);
            }
        }
        return ans;
    }
};
