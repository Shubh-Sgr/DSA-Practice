class Solution {
public:
    int numSplits(string s) {
        int l[26],r[26];
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        
        int n=s.size();
        int rCount=0,lCount=0;
        int ans=0;
        
        for (int i=0; i<n; i++)
        {
            
            if ((r[s[i]-'a']++)==0)
            {
                rCount++;
            }
        }
        for (int i=0; i<n; i++)
        {
            
            if ((l[s[i]-'a']++)==0)
            {
                lCount++;
            }
            if ((--r[s[i]-'a'])==0)
            {
                rCount--;
            }
            if (lCount==rCount)
            {
                ans++;
            }
        }
        return ans;
    }
};
