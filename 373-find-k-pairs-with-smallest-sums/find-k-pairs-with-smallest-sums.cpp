class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        if(nums1.empty() || nums2.empty() || k==0)
            return {};

        int n = nums1.size();
        int m = nums2.size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        set<pair<int,int>> vis;

        pq.push({nums1[0]+nums2[0], {0,0}});
        vis.insert({0,0});

        vector<vector<int>> ans;

        while(!pq.empty() && ans.size() < k){

            auto cur = pq.top();
            pq.pop();

            int i = cur.second.first;
            int j = cur.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if(i+1 < n && !vis.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j], {i+1,j}});
                vis.insert({i+1,j});
            }

            if(j+1 < m && !vis.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1], {i,j+1}});
                vis.insert({i,j+1});
            }
        }

        return ans;
    }
};