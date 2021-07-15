class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target<matrix[0][0])
        {
            return false;
        }
        int n=matrix.size();
        int m=matrix[0].size();
        int row_to_srch=-1;
        for (int i=0; i<n-1; i++)
        {
            if (target>=matrix[i][0] && target<matrix[i+1][0])
            {
                row_to_srch=i;
                break;
            }
        }
        if (row_to_srch==-1)
        {
            row_to_srch=n-1;
        }
        // cout<<row_to_srch<<" ";
        int st=0;
        int mid,end=m-1;
        while (st<=end)
        {
            mid=(st+end)/2;
            if (matrix[row_to_srch][mid]==target)
            {
                return true;
            }
            else if(matrix[row_to_srch][mid]>target)
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        return false;
    }
};
