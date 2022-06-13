class Solution {
public:
    void Utils(int left, int right, string s, int &count)
    {
        int n = s.size();
        
        while (left>=0 && right<n && s[left]==s[right])
        {
            count++;
            left--;
            right++;
        }
    }
    
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        
        for (int i=0; i<n; i++)
        {
            Utils(i,i,s,count);
            Utils(i,i+1,s,count);
        }
        
        return count;
    }
};
