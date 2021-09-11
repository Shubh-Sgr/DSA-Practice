class Solution {
public:
    string countAndSay(int n) {
        if (n==1)
        {
            return "1";
        }
        string temp=countAndSay(n-1);
        string ans;
        
        int count=1;
        char comp=temp[0];
        
        for (int i=1; i<temp.size(); i++)
        {
            if (temp[i]==comp)
            {
                count++;
            }
            else
            {
                ans+=to_string(count);
                ans.push_back(comp);
                count=1;
                comp=temp[i];
            }
        }
         ans+=to_string(count);
        ans.push_back(comp);
        // cout<<ans<<" ";
        
        return ans;
    }
};
