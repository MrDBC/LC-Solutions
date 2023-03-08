class Solution {
    unordered_map<int, int> index;
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n= arr.size();
        
        for(int i=0; i<n; i++)
            index[arr[i]]=i;
        
        int maxlen = 0;
        
        // (a, b , c)
        for(int a=0; a<= n-3; a++)
            for(int b=a+1; b<=n-2; b++)
                maxlen = max(maxlen, dfs(arr, a, b));
       
        return (maxlen !=0)? maxlen +2: 0 ;
    }
    int dfs( vector<int>& arr, int a, int b){
        
        int val_c = (arr[a] + arr[b]) ;
        
        if( index.find(val_c) != index.end() )
            return  1+ dfs(arr, b, index[val_c]);
        else
            return 0;
        
        
    }
};
