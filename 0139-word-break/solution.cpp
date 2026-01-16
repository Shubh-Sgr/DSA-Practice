class Solution {
public:
    bool  wordBreakUtil(string s,unordered_map<string,int> &ump){
        vector<bool> dp(s.size(), false);
        dp[0] = true;

        for (int i=1; i<=s.size(); i++){
            for (int j = i-1; j>=0; j--){
                if (dp[j]){
                    string temp = s.substr(j,i-j);
                    if (ump.find(temp)!=ump.end()){
                        dp[i]= true;
                        break;
                    } 
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> ump;
        int m = wordDict.size();
        for (int i=0; i<m; i++){
            ump[wordDict[i]] = 1;
        }
        return wordBreakUtil(s,ump);
    }
};
