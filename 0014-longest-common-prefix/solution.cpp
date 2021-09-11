class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n=strs.size();
        if (n==1)
        {
            return strs[0];
        }
        int j=0;
        
        while (1){ 
            
            for (int i=0; i<n; i++)
            {
                if (j>=strs[i].size() || (i>0 && strs[i][j]!=strs[i-1][j]))
                {
                    return ans;
                }
            }
            
            ans+=strs[0][j];
            j++;
        }
        
        return ans;
    }
};
