class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& A) {
        long long ans = 1;
        int n = A.size();
        vector <pair <int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({A[i], i});
        }
        sort(v.begin(), v.end());
        for(int i = n - 2; i >= 0; i--) {
            ans += (v[i].second > v[i + 1].second) ? n - i : 1;
        }
        return ans;
    }
};