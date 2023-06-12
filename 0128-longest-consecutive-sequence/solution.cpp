class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();

        for (int i=0; i<n; i++){
            mp[nums[i]] = 1;
            cout<<"nums[i] "<<nums[i];
        }
        if (n==0){
            return 0;
        }
        int ans=1;

        for (map<int,int>::iterator it = mp.begin(); it!=mp.end(); it++){
            int num = it->first;
            if (mp.find((num)+1)!=mp.end() && mp[num]==1){
                int count=1;
                num++;
                cout<<"if "<<num;
                mp[num]=0;
                while (mp.find((num))!=mp.end()){
                    mp[num]=0;
                    cout<<"while "<<num;
                    count++;
                    num++;
                }
                if (count>ans){
                    ans = count;
                }
            }
        }
        return ans;
    }
};
