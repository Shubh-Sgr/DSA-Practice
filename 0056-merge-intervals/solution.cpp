class Solution {
public:
    // static bool comp(vector<int> v1,vector<int> v2)
    // {
    //     if (v1[0]<v2[0] || (v1[0]==v2[0] && v1[1]<v2[1]))
    //     {
    //         return true;
    //     }
    //    return false;
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int s=intervals[0][0],e=intervals[0][1];
        for (int i=1; i<intervals.size(); i++)
        {
            cout<<e<<" ";
            if (intervals[i][0]>e)
            {
                temp.push_back(s);
                temp.push_back(e);
                ans.push_back(temp);
                temp.clear();
                s=intervals[i][0];
                e=intervals[i][1];
            }else{
                e=e>intervals[i][1]?e:intervals[i][1];
            }
        }
        temp.push_back(s);
        temp.push_back(e);
        ans.push_back(temp);
        return ans;
    }
};
