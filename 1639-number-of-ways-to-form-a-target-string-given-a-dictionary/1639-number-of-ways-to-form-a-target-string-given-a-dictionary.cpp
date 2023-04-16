class Solution {
private:
    int m , n; // m means the len of the word; n means the len of the target;
    vector<vector<int>> memo;
public:
    int numWays(vector<string>& words, string target) {
        m = words[0].size();
        n = target.size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        
        vector<vector<int>> cnt(26, vector<int>(m+1, 0));
        for (auto& word : words) {
            for (int i = 0; i < m; ++i) {
                cnt[word[i]-'a'][i]++;
            }
        }
        
        return dfs(target, cnt, 0, 0);
    }
    
    const int mod = pow(10, 9) + 7;
    //i means the location of word, j means the location of the target;
    int dfs(string& target, vector<vector<int>>& cnt, int i, int j) {
        
        
        
        if (j >= n) return 1; // search the end of the target, get one solution;
        
        if (i >= m) return 0; //search the end of the word, no match
        
        if (memo[i][j] >= 0) return memo[i][j];
        
        long res = dfs(target, cnt, i + 1, j); // skip the i index;
        
        char c = target[j] - 'a';
        // use the i index
        if (cnt[c][i] > 0) { 
            res += (long)cnt[c][i] * dfs(target, cnt, i+1, j+1);
            res = res % mod;
        }
        memo[i][j] = (int)res;
        
        // cout << i << " " << j << " " << res << endl;
        return memo[i][j];
    }
};