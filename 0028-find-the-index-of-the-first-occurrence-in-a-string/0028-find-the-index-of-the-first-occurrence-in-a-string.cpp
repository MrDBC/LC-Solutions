class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx = haystack.find( needle);
        return ( idx != string::npos)? idx: -1;
    }
};