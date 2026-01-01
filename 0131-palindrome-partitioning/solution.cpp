class Solution {
public:
    static bool isPallindrome(string s, int i, int j ,int n){
        bool res = true;
        while (i<j){
            if (s[i]!=s[j]){
                res= false;
                break;
            }else{
                i++;
                j--;
            }
        }
        return res;
    }

    static void partitionUtil(string s, int ind, vector<string> temp, vector<vector<string>> &ans, int n){
        if (ind > n){
            ans.push_back(temp);
            return;
        }

        for (int i=ind; i<=n; i++){
            bool left = isPallindrome(s,ind,i,n);
            if (left){
                string resStr;
                for (int j = ind; j<=i; j++){
                    resStr.push_back(s[j]);
                }
                temp.push_back(resStr);
                partitionUtil(s,i+1,temp,ans,n);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        partitionUtil(s,0,temp,ans,n-1);
        return ans;
    }
};
