class Solution {
    vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> ones{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                    "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

public:
    string numberToWords(int num) {
        if(!num)
            return "Zero";
        
        return dfs(num).substr(1);
    }
    string dfs(int num){
        if( !num)
            return ones[0];
        if( num>=1000000000)
            return dfs(num/1000000000)+" Billion" + dfs(num%1000000000);
        if( num>=1000000)
            return dfs(num/1000000)+" Million" + dfs(num%1000000);
        if( num>=1000)
            return dfs(num/1000)+" Thousand" + dfs(num%1000);
        if( num>=100)
            return dfs(num/100)+" Hundred" + dfs(num%100);
        if( num>=20)
            return " "+tens[num/10]+  dfs(num%10);
     
        return " "+ones[num];
    }
};