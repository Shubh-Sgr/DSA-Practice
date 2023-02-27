class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double> mp;

        int n = speed.size();

        for (int i=0; i<n; i++){
            mp[-position[i]] = (double)(target-position[i])/speed[i];
        }

        double currSlow = 0;
        int ans=0;

        for (map<int,double>::iterator it = mp.begin() ; it!=mp.end(); it++){
            if (it->second > currSlow){
                currSlow = it->second;
                ans++;
            }
        }
        return ans;
    }
};
