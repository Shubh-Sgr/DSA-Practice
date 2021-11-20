class Solution {
public:
    string palindrome(string s,int i,int j)
    {
        string ans="";
        int end=j;
        while (i<end)
        {
            if (s[i]!=s[end])
            {
                return "";
            }
            else
            {
                ans+=s[i];
            }
            i++;
            end--;
        }
        for (int l=i; l<=j; l++)
        {
            ans+=s[l];
        }
        return ans;
    }
    void partitionUtil(string s,int i,int j,vector<vector<string>> &ans,vector<string> temp)
    {
        if (i>j)
        {
            ans.push_back(temp);
            return;
        }
        for (int k=i; k<=j; k++)
        {
            if (palindrome(s,i,k)!="")
            {
                temp.push_back(palindrome(s,i,k));
                partitionUtil(s,k+1,j,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n=s.size()-1;
        partitionUtil(s,0,n,ans,temp);
        return ans;
    }
};
