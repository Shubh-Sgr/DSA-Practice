class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n), ryt(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            st.pop();
            if(st.empty())
            left[i]=0;
            else
            left[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            st.pop();
            if(st.empty())
            ryt[i]=n-1;
            else
            ryt[i]=st.top()-1;
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long a=(arr[i]*(i-left[i]+1))%1000000007;
            a=(a*(ryt[i]-i+1))%1000000007;
            ans+=a;
            ans%=1000000007;
        }
        return ans;

    }
};
