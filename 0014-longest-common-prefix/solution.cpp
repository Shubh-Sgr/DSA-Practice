class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        int n = strs.size();
        string ans = "";
        while(1){
            if (i>=strs[0].size()){
                break;
            }
            char temp = strs[0][i];
            bool flag = true;
            for (int j=1; j<n; j++){
                if (strs[j][i]!=temp || i>=strs[j].size()){
                    flag = false;
                    break;
                }
            }
            if (flag){
                ans.push_back(strs[0][i]);
                i++;
            }else{
                ans;
                break;
            }
        }
        return ans;
    }
};
