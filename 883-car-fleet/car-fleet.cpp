class Solution {
public:
    static bool compare(pair<int,int> p1, pair<int,int> p2){
        return p1.first>p2.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> carInfo;
        for (int i=0; i<n; i++){
            carInfo.push_back({position[i],speed[i]});
        }
        sort(carInfo.begin(), carInfo.end(),compare);
        double maxTime = 0.0;
        int fleet = 0;
        for (int i=0; i<n; i++){
            double currentTime = (double)(target-carInfo[i].first)/carInfo[i].second;
            if (maxTime<currentTime){
                maxTime = currentTime;
                fleet++;
            }
        }
        return fleet;
    }
};