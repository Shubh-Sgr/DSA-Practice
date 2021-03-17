class Solution {
public:
    int min(int a, int b)
    {
        if (a<b)
        {
            return a;
        }
        return b;
    }
    int maxArea(vector<int>& height) {
        int max=INT_MIN;
        int l=0;
        int r=height.size()-1;
        while (l<r)
        {
            if (max<(r-l)*min(height[r],height[l]))
            {
                max=(r-l)*min(height[r],height[l]);
            }
            if (height[r]<height[l])
            {
                r--;
            }
            else
            {
                 l++;               
            }
        }
        return max;
    }
};
