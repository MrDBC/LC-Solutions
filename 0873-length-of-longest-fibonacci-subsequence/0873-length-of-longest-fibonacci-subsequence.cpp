class Solution {
    unordered_map<int, int> index;
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n= arr.size();
        
        for(int i=0; i<n; i++)
            index[arr[i]]=i;
        
        int maxlen = 0;
        // (a, b , c)
        for(int c=2; c<n; c++){
            for(int b=c-1; b>=1; b--){
                
                // int val_a = arr[c] - arr[b];
                // if( index.count(val_a))  // +1 for counting val_c
                maxlen = max(maxlen, dfs(arr, b, c));
            }
        }
       
        return (maxlen !=0)? maxlen +2: 0 ;
    }
    int dfs( vector<int>& arr, int b, int c){
        
        int val_a = (arr[c] - arr[b]) ;
        
        if( index.find(val_a) != index.end() and index[val_a] < b)
            return  1+ dfs(arr, index[val_a], b);
        else
            return 0;
        
        
    }
};
