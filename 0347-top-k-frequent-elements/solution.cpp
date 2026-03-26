class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        int n = nums.size();

        for (int i=0; i<n; i++){
            ump[nums[i]]++;
        }

        for (unordered_map<int,int>::iterator it=ump.begin(); it!=ump.end(); it++){
            pq.push({it->second, it->first});
        }

        pair<int,int> top;
        for (int i=0; i<k; i++){
            top = pq.top();
            res.push_back(top.second);
            pq.pop();
        }

        return res;
    }
};
