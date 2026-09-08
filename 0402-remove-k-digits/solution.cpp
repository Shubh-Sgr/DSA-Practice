class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        int n = num.size();
        int i = 0;

        while (i < n) {

            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
            i++;
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int j = 0;
        while (j < ans.size() && ans[j] == '0') {
            j++;
        }

        ans = ans.substr(j);
        if (ans.empty()) {
            return "0";
        }

        return ans;
    }
};
