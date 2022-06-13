class Solution {
public:
    
    void Utils(int left, int right, string s, int &max,string &ans)
    {
        int n = s.size();
        
        while (left>=0 && right<n && s[left]==s[right])
        {
            if (max<right-left+1)
            {
                max=right-left+1;
                ans=s.substr(left,max);
            }
            left--;
            right++;
        }
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int max = 0;
        string ans="";
        
        for (int i=0; i<n; i++)
        {
            Utils(i,i,s,max,ans);
            Utils(i,i+1,s,max,ans);
        }
        
        return ans;
    }
};
