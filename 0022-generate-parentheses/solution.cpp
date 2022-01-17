class Solution {
public:
    void Util(int open, int close,vector<string> &ans,string s)
    {
        if (open ==  0 && close == 0)
        {
            ans.push_back(s);
            return;
        }
        if (open>0){
            Util(open-1,close+1,ans,s+"(");
        }
        if (close>0)
        {
            Util(open,close-1,ans,s+")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        Util(n,0,ans,s);
        return ans;
    }
};
