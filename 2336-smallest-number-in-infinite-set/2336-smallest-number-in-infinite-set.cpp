class SmallestInfiniteSet {
    set<int> s;
    int leftpointer =1;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int setmin=INT_MAX;
        
        if( s.size())
            setmin = *(s.begin());
        
        if( leftpointer < setmin){
            return leftpointer++;
        }
        else{
            s.erase(setmin);
            return setmin;
        }
    }
    
    void addBack(int num) {
        if( num< leftpointer){
            s.insert(num);// 1
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */