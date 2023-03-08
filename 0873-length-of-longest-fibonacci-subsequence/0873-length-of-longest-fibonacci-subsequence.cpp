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

// class Solution {
// public:
    
//     int find(vector<int>&A, unordered_map<int,int>&m, vector<vector<int> >&dp, int cur, int prev) {
        
//         // if(dp[cur][prev]!=-1)
//         //     return dp[cur][prev];
        
//         int ans = 2;
//         if(m.find(A[cur]+A[prev])!=m.end()) {
//             int new_pos = m[A[cur]+A[prev]];
//             ans = max(ans, 1 + find(A,m,dp,new_pos,cur));
//         }
//         // dp[cur][prev]=ans;
//         return ans;
//     }
//     int lenLongestFibSubseq(vector<int>& A) {
//         vector<vector<int> >dp(A.size(), vector<int>(A.size(),-1));
//         unordered_map<int,int>m;
//         for(int i=0;i<A.size();i++) {
//             m[A[i]]=i;
//         }
//         int ans = 0;
//         for(int i=0;i<A.size();i++) {
//             for(int j=i+1;j<A.size();j++) {
//                 if(m.find(A[i]+A[j])!=m.end()) {
//                     int new_pos = m[A[i]+A[j]];
//                     ans = max(ans, 1 + find(A,m,dp,new_pos,j));
//                 }
//             }
//         }
//         return ans;
//     }
// };