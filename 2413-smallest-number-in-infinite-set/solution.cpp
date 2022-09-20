class SmallestInfiniteSet {
public:
    int curr;
    set<int> s ;
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        int res;
        if (s.size()){
            res = *s.begin();
            s.erase(res);
        }
        else{
            curr++;
            res = (curr-1);
        }
        return res;
    }
    
    void addBack(int num) {
        if (curr>num){
            s.insert(num);
        }
    }
};

