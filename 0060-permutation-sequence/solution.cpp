class Solution {
public:
    void getPermutationUtil( vector<int>v,string &ans,int k,int n,int fact[])
    {
        if (n==1)
        {
            ans+=to_string(v.back());
            return;
        }
        
        int index=k/fact[n-1];
        if (k%fact[n-1]==0)
        {
            index--;
        }
        ans=ans+to_string(v[index]);
        v.erase(v.begin()+index);
        k-=index*fact[n-1];
        getPermutationUtil(v,ans,k,n-1,fact);
    }
    
    string getPermutation(int n, int k) {
        vector<int> v;
        for (int i=1; i<=n; i++)
        {
            v.push_back(i);
        }
        string ans="";
        int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};
        getPermutationUtil(v,ans,k,n,fact);
        return ans;
    }
};
