class Solution {
public:
    
    // I TRIED TOP DOWN , ITS SAYS TLE 20/44
    // I TRIED COPY PASTING ANOTHER TOPDOWN , STILL TLE AT 32/44
    
    string largestMultipleOfThree(vector<int>& digits) {
      int rem1[] = {1, 4, 7, 2, 5, 8}, rem2[] = {2, 5, 8, 1, 4, 7};
      int sum = 0, freq[10] = {};

      for (auto d : digits) 
          ++freq[d], sum += d;

      while (sum % 3 != 0) {
        for (auto i : (sum % 3 == 1) ? rem1 : rem2) 
          if (freq[i]) {
            --freq[i];
            sum-=i;
            break;
          }
        
      }
        
     string res = "";
      for (int i = 9; i >= 0; --i)
        res += string(freq[i], '0' + i);
        
      return res.size() && res[0] == '0' ? "0" : res;
    }
};
