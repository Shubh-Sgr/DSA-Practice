class Solution {
public:
    static void combinationSumutil(vector<int>& candidates, int ind, vector<int> temp, int target,vector<vector<int>> &ans, int n){
        if (target == 0){
            ans.push_back(temp);
            return;
        }
        else if (target > 0){
            for (int i=ind; i<n; i++){
                temp.push_back(candidates[i]);
                combinationSumutil(candidates, i, temp, target-candidates[i], ans, n);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        combinationSumutil(candidates, 0, temp, target, ans, n);
        return ans;
    }
};
