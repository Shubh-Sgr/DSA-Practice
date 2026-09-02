class Solution {
public:
    void findHappyString(int n,int k,string curr,vector<string> &ans){
        if (curr.size()==n){
            ans.push_back(curr);
            return;
        }
            for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            if (curr.size() > 0 && curr.back() == currentChar)
                continue;
            findHappyString(n, k, curr + currentChar, ans);
           
        }
    }
    string getHappyString(int n, int k) {
       string curr = "";
       vector<string> ans;
       findHappyString(n,k,curr,ans);
       if (ans.size() < k)
            return "";
       return ans[k-1];
    }
};
