class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        vector<vector<int>> matrix (n, vector<int> (n, -1));
        for(int i = 0; i < n; i++)
            map[arr[i]] = i;
        int maxS = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                maxS = max(maxS, dp(i, j,  map, matrix, arr));
        return maxS == 0 ? 0 : 2 + maxS;
        
    }
    
    int dp(int i, int j, unordered_map<int, int>& map, vector<vector<int>>& matrix, vector<int>& arr)
    {
        if (matrix[i][j] != -1)                         return matrix[i][j];
        if (map.find(arr[i] + arr[j]) == map.end())     return matrix[i][j] = 0;
        return matrix[i][j] = 1 + dp(j,  map[arr[i] + arr[j]], map, matrix, arr);
    }
};