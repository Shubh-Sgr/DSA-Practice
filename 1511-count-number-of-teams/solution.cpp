class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;
        
        for (int i=0; i<n; i++)
        {
            int leftL=0,leftS=0,rightL=0,rightS=0;
            for (int j=0; j<i; j++)
            {
                if (rating[j]<rating[i])
                {
                    leftS++;
                }
                else
                {
                    leftL++;
                }
            }
            
            for (int j=i+1; j<n; j++)
            {
                if (rating[j]<rating[i])
                {
                    rightS++;
                }
                else
                {
                    rightL++;
                }
            }
            
            ans+=leftS*rightL + leftL*rightS;
        }
        return ans;
    }
};
