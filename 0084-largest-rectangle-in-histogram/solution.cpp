class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int lessLeft[n];
        int lessRight[n];
        
        lessLeft[0]=-1;
        lessRight[n-1]=n;
        
        for (int i=1; i<n; i++)
        {
            int indLess=i-1;
            while (indLess>=0 && heights[indLess]>=heights[i])
            {
                indLess=lessLeft[indLess];
            }
            
            lessLeft[i]=indLess;
        }
        
        for (int i=n-2; i>=0; i--)
        {
            int indLess=i+1;
            while (indLess<n && heights[indLess]>=heights[i])
            {
                indLess=lessRight[indLess];
            }
            
            lessRight[i]=indLess;
        }
        
        int ans=0;
        
        for (int i=0; i<n; i++)
        {
            ans=max(ans,(lessRight[i]-lessLeft[i]-1)*heights[i]);
        }
    return ans;
    }
};
