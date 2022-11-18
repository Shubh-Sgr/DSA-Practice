class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n<=1){
            return 0;
        }
        int ans=0;
        stack<int> st;
        
        for (int i=0; i<n; i++){
            if (s[i]=='('){
                st.push(i);
            }
            else{
                if (!st.empty() && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        
        int l=0,h=n;
        while(!st.empty()){
            l=st.top();
            ans = max(ans,h-l-1);
            st.pop();
            h=l;
        }
        ans=max(ans,h);
       
        return ans;
    }
};
