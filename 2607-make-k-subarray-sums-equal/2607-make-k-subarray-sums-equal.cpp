class Solution {
public:
    // https://leetcode.com/problems/make-k-subarray-sums-equal/discuss/3366373/k-Cycles-O(n)
    long long makeSubKSumEqual(vector<int>& arr, int k) {
         long long sz = arr.size(), res = 0;
        for (int i = 0; i < sz; ++i) {
            vector<int> cycle;
            for (int j = i; arr[j] != 0; j = (j + k) % sz) {
                cycle.push_back(arr[j]);
                arr[j] = 0;
            }
            nth_element(begin(cycle), begin(cycle) + cycle.size() / 2, end(cycle));
            for (int n : cycle)
                res += abs(n - cycle[cycle.size() / 2]);
        }
        return res;
    }
};