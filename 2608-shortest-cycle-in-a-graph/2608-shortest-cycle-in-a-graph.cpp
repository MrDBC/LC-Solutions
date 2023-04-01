class Solution
{
public:
    int ans = INT_MAX;
    void dfs(vector<int> adj[], int node, int d, unordered_map<int, int> &mp, int par, vector<int> &vis)
    {

        vis[node] = 1;
        mp[node] = d;
        for (auto it : adj[node])
            if (!vis[it])
                dfs(adj, it, d + 1, mp, node, vis);
            else if (par != it)
                ans = min(ans, abs(d - mp[it]) + 1);
        
    }

    int findShortestCycle(int n, vector<vector<int>> &edges)
    {

        vector<int> adj[n + 1];
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 0; i < n; i++)
        {
            vector<int> vis(n, 0);
            unordered_map<int, int> mp;
            dfs(adj, i, 0, mp, -1, vis);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};