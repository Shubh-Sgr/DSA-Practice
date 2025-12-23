class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(), comp);
        int n = intervals.size();
        int end = intervals[0][1];
        int start = intervals[0][0];

        for (int i=1; i<n; i++){
            if (intervals[i][0] > end){
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                res.push_back(temp);
                start = intervals[i][0];
                end = intervals[i][1];
            }else if (intervals[i][0] <= end && intervals[i][1] >= end){
                end = intervals[i][1];
            }
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        res.push_back(temp);
        return res;
    }
};
