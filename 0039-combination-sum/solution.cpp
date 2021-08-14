class Solution {
public:
    
    void combinationSumUtil(vector<int> candidates,vector<int> temp,set<vector<int>> &s,int target)
    {
        if (target==0)
        {
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        if (target<0)
        {
            return;
        }
        for (int i=0; i<candidates.size(); i++)
        {
            
           
                temp.push_back(candidates[i]);
                combinationSumUtil(candidates,temp,s,target-candidates[i]);
                temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> s;
        combinationSumUtil(candidates,temp,s,target);
        for (set<vector<int>>::iterator it=s.begin(); it!=s.end(); it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};
