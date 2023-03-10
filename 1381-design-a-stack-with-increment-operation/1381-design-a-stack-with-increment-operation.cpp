class CustomStack {
    int idx=0;
    vector<int> arr;
    
public:
    CustomStack(int maxSize) {
        arr.resize(maxSize, -1);
    }
    
    void push(int x) {
        if( idx== arr.size())
            return;
        arr[idx++] = x;
    }
    
    int pop() {
        if( idx==0)
            return -1;
        int popped_item = arr[--idx];
        arr[idx] = -1;
        return popped_item;
    }
    
    void increment(int k, int val) {
        
        for(int i=0; i<min( (int)arr.size(), k); i++)
            if( arr[i] != -1)
                arr[i]+= val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */