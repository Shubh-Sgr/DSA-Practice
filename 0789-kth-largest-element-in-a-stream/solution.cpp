class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int cap = -1;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        cap = k;
        for (int i=0; i<n; i++){
            if (pq.size()==k && pq.top()<=nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            if (pq.size()<k){
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if (pq.size()==cap && pq.top()<=val){
            pq.pop();
            pq.push(val);
        }
        if (pq.size()<cap){
            pq.push(val);
        }
        int ans = pq.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
