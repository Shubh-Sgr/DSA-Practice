class Solution {
public:
    static bool srt(pair<int,int> p1, pair<int,int> p2){
        return p1.second>p2.second;
    }
    
    int minSetSize(vector<int>& arr) {
        int n= arr.size();
        unordered_map<int,int> ump;
        
        for (int i=0; i<n; i++){
            ump[arr[i]]++;
        }
        
        int count=0;
        int num=0;
        vector<int> v;
        
        for (auto it = ump.begin(); it!=ump.end(); it++){
            v.push_back(it->second);
        }
        sort(v.begin(),v.end());
        int len = v.size();
        for (int i=len-1; i>=0; i--){
            cout<<count<<" "<<(n/2)<<endl;
            if (count<(n/2)){
                count+=v[i];
                num++;
            }
            else{
                break;
            }
        }
        return num;
    }
};
