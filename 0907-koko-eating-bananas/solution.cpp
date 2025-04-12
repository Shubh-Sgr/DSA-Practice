class Solution {
public:
    long long getTotalHoours(vector<int>& piles, int minVal){
        long long total = 0;
        for (int i=0; i<piles.size(); i++){
            int val = ceil(piles[i]/(double(minVal)));
            total+=val;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        int ans = -1;
        int mid;
        for (int i=0; i<piles.size(); i++){
            if (high < piles[i]){
                high = piles[i];
            }
        }
        while (low <= high){
            mid = low + (high-low)/2;
            long long hoursToEatAll = getTotalHoours(piles, mid);
            
            if (hoursToEatAll <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
