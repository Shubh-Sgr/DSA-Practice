class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
        stack < int > st;
        vector<int> leftMin(n), rightMin(n);
        if (heights.size()==1){
            return heights[0];
        }

        for (int i=0; i<n; i++){
            while (!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty()){
                leftMin[i] = -1;
            }else{
                leftMin[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()){
            st.pop();
        }

        for (int i=n-1; i>=0; i--){
            while (!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty()){
                rightMin[i] = n;
            }else{
                rightMin[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = INT_MIN;
        for (int i=0; i<n; i++){
            cout<<"leftMin"<<leftMin[i]<<" "<<rightMin[i]<<" ";
            maxArea = max(maxArea , heights[i]*((rightMin[i]-leftMin[i])-1));
        }
        return maxArea;
    }
};
